#include <stdio.h>

void squeeze(char s1[], char s2[]);
int any(char s1[], char s2[]);

int main() {
    char s1[] = "hello there";
    char s2[] = "tr";
    squeeze(s1, s2);
    printf("%s\n", s1);

    char s3[] = "hello there";
    char s4[] = "lh";
    printf("%d\n", any(s3, s4));
    
    return 0;
}

void squeeze(char s1[], char s2[]) {
    int i,j,k,c1,c2;
    for (i = k = 0; (c1 = s1[i]) != '\0'; ++i) {
        int found = 0;
        for (j = 0; (c2 = s2[j]) != '\0'; ++j) {
            if (c1 == c2) {
                found = 1;
                break;
            }
        }
        if (found != 1)
            s1[k++] = c1;
    }
    s1[k] = '\0';
}

int any(char s1[], char s2[]) {
    int i,j,c1,c2;
    for (i = 0; (c1 = s1[i]) != '\0'; ++i) {
        for (j = 0; (c2 = s2[j]) != '\0'; ++j) {
            if (c1 == c2)
                return i;
        }
    }
    return -1;
}