#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
    char a[] = "Hello\nThere\t\tFella";
    char b[100];
    escape(b, a);
    printf("%s\n", b);
    char c[] = "Hello\\nThere\\t\\tDog";
    char d[100];
    unescape(d,c);
    printf("%s\n", d);
    char e[] = "Hello\\nThere\\t\\tDog\\Whats\\Up";
    char f[100];
    unescape(f,e);
    printf("%s\n", f);
    return 0;
}

void escape(char s[], char t[]) {
    int c,i,j;
    for(i = j = 0; (c = t[i]) != '\0'; ++i) {
        switch (c) {
        case '\n': case '\t': case '\b':
            s[j++] = '\\';
            switch (c) {
            case '\n':
                c = 'n';
                break;
            case '\t':
                c = 't';
                break;
            case '\b':
                c = 'b';
                break;
            }
            break;
        default:
            break;
        }
        s[j++] = c;
    }
}

void unescape(char s[], char t[]) {
    int c,i,j;
    for(i = j = 0; (c = t[i]) != '\0'; ++i) {
        switch (c) {
        case '\\':
            c = t[i + 1];
            switch (c) {
            case 't':
                c = '\t';
                ++i;
                break;
            case 'n':
                c = '\n';
                ++i;
                break;
            case 'b':
                c = '\b';
                ++i;
                break;
            default:
                c = t[i];
                break;
            }
        default:
            break;
        }
        s[j++] = c;
    }
}