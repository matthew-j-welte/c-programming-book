#include <stdio.h>
#include <string.h>

int min_int = -(int)((unsigned int)~0 >> 1) -1;

void reverse(char str[]);
void itoa(int n, char str[]);
void itoa_width(int n, int width, char s[]);
void itob(int n, int base, char str[]);

int main() {
    char a[100];
    int min = -(int)((unsigned int)~0 >> 1) -1;
    itoa(min, a);
    printf("%s\n", a);

    char b[100];
    int num = 150;
    int width = 11;
    itoa_width(num, width, b);
    printf("|%s|\n", b);
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
    int i, sign, orig;
    orig = n;
    if (orig == min_int)
        n += 1;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        str[i++] = '-';
    str[i] = '\0';
    reverse(str);
    if (orig == min_int)
        str[i - 1]++;
}

void itoa_width(int n, int width, char str[]) {
    int i, x, c, remaining, partition;
    char str_piece[100];

    itoa(n, str_piece);
    i = 0;

    remaining = width - strlen(str_piece);
    partition = remaining / 2;
    if (remaining % 2)
        str[i++] = ' ';
    for (x = 0; x < partition; ++x, ++i)
        str[i] = ' ';
    for (x = 0; (c = str_piece[x]) != '\0'; ++x, ++i)
        str[i] = c;
    for (x = 0; x < partition; ++x, ++i)
        str[i] = ' ';
    str[i] = '\0';
}

void itob(int n, int base, char str[]) {
    // do what itoa does but use the base instead of 10 and add
    // logic to continue outputting until num / base == 1.. or 0?
    // if base is greater than 10 add some logic to jump the char to
    // the alpha chars.. and I guess limit it to 35/36 base?
    // for larger bases you will have to also do a check like:
    // if base is larger than num, grab the next num as well then start
    // doing the check from there
}
