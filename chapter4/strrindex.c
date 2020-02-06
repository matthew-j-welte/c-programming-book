#include <stdio.h>

int strrindex(char s[], char t[]);

int main () {
    printf("%d\n", strrindex("Hello", "l"));
    return 0;
}

int strrindex(char s[], char t[]) {
    int i, j, k, latest_found;
    latest_found = -1;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            latest_found = i;
    }
    return latest_found;
}