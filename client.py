import inspect
import graphene
from gql_query_builder import GqlQuery

class User(graphene.ObjectType):
    age = graphene.Int()
    name = graphene.String()

class Post(graphene.ObjectType):
    status = graphene.String()
    timestamp = graphene.Float()
    user = graphene.Field(User)

class MetaParams(graphene.ObjectType):
    task_id = graphene.String()
    iid = graphene.String()
    application = graphene.String()
    post = graphene.Field(Post)

class Query(graphene.ObjectType):
    get_metadata = graphene.Field(MetaParams)

class QueryResolver:
    def __init__(self, graphql_obj):
        self.parent_obj = graphql_obj

    @classmethod
    def get_graphene_fields(cls, cls_type):
        all_fields = [x for x in inspect.getmembers(cls_type) if not x[0].startswith("_")]
        non_builtins = [x for x in all_fields if cls.is_custom_field(x[1]) or cls.is_scalar(x[1])]
        return non_builtins

    @staticmethod
    def is_scalar(field_obj):
        return isinstance(field_obj, graphene.types.scalars.Scalar)

    @staticmethod
    def is_custom_field(field_obj):
        return isinstance(field_obj, graphene.types.field.Field)

    @classmethod
    def extract_scalars(cls, cls_type):
        for field, field_obj in cls.get_graphene_fields(cls_type):
            if cls.is_scalar(field_obj):
                yield field

    @staticmethod
    def snake_to_camel(field_name: str):
        field_partitions = field_name.split("_")
        joined_field = "".join(x[0].upper() + x[1:] for x in field_partitions)
        return joined_field[0].lower() + joined_field[1:]

    def resolve(self, query_name, **kwargs):
        def inner_resolve(graphene_obj):
            fields = self.get_graphene_fields(graphene_obj)
            scalars = list(self.extract_scalars(graphene_obj))
            built_fields = []
            for mem, _ in fields:
                if mem in scalars:
                    built_fields.append(self.snake_to_camel(mem))
                else:
                    field_type = getattr(graphene_obj, mem)._type
                    built_fields.append(GqlQuery().fields(inner_resolve(field_type), name=self.snake_to_camel(mem)).generate())
            return built_fields

        # mp = MetaParams(task_id = "2000", application = "WELTE-APP", post = Post())
        # for x in inspect.getmembers(mp):
        #     print(x)

        query_obj = getattr(self.parent_obj, query_name)._type
        camel_kwargs = {self.snake_to_camel(k):v for k,v in kwargs.items()}
        fields = GqlQuery().fields(inner_resolve(query_obj)).query(self.snake_to_camel(query_name), input=camel_kwargs).operation().generate()
        print(fields)

qr = QueryResolver(Query)
qr.resolve("get_metadata", task_id = "2000")
        