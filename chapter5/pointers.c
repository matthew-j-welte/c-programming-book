#include <stdio.h>

void strcat_p(char *s, char *t);
int strend_p(char *s, char *t);

int main() {
    char a[] = "Hello";
    char b[] = "There";
    strcat_p(a, b);

    printf("%s\n", a);

    char c[] = "HelloThereYo";
    char d[] = "Yo";
    printf("%d\n", strend_p(c, d));
    return 0;
}

void strcat_p(char *s, char *t) {
    while (*s++)
        ;
    s--;
    while (*s++ = *t++)
        ;
}

int strend_p(char *s, char *t) {
    char *t_start_addr = t;
    char *last_s_addr;
    while (*s++) {
        t = t_start_addr;
        last_s_addr = s;
        if (*s == *t) {
            while(*s++ == *t++) {
                if (*s == '\0' && *t == '\0')
                    return 1;
            }
            s = last_s_addr;
        }
    }
    return 0;
}