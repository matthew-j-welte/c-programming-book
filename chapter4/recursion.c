#include <stdio.h>
#include <string.h>

void reverse(char str[]);
void itoa(int n, char str[]);
void recursive_itoa(int n, char str[], int i);

int main() {
    char a[100];
    recursive_itoa(123456789, a, 0);
    printf("%s\n", a);
    return 0;
}

void reverse(char str[]) {
    int c, i, j;
    for(i = 0, j = strlen(str)-1; i < j; i++, j--) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}

void itoa(int n, char str[]) {
    int i, c, sign;
    if ((sign = n) < 0)
        n = -n;

    i = 0;
    do {
        c = n % 10;
        str[i++] = c + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        str[i++] = '-';
    str[i] = '\0';
    reverse(str);
}

void recursive_itoa(int n, char str[], int i) {
    int c;

    c = n % 10;
    str[i++] = c + '0';
    
    if (n < 10) {
        str[i] = '\0';
        reverse(str);
    }
    else if (n / 10)
        recursive_itoa(n / 10, str, i);

}