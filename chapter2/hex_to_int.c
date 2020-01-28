#include <stdio.h>
#include <math.h>
#include <string.h>

#define OUT_OF_RANGE -1
#define FALSE 0
#define TRUE  1

void htoi(char s[]);
int has_hex_prefix(char s[]);
int to_hex_range_int(int c);
long powr(int num, int x);

int main() {
    htoi("F");
    htoi("555");
    htoi("F555AB");
    htoi("0XF555AB");
    htoi("0xF555AB");
    return 0;
}

void htoi(char s[]) {
    int c,i, exponent;
    long n = 0;

    exponent = strlen(s) - 1;
    i = 0;
    if (has_hex_prefix(s) == TRUE) {
        i = 2;
        exponent -= 2;
    }
    
    printf("Hex Value: %s\n", s);
    for(; (c = s[i]) != '\0'; ++i) {
        if ((c = to_hex_range_int(c)) == OUT_OF_RANGE) {
            printf("char at index %i is not a valid hex digit\n", i);
            return;
        }
        n = n + (powr(16, exponent) * c);
        --exponent;
    }
    printf("Integer value: %ld\n", n);
}

int has_hex_prefix(char s[]) {
    if (s[0] == '\0')
        return FALSE;
    else if (s[0] == '0') {
        if (s[1] == '\0')
            return FALSE;
        else if (s[1] == 'X' || s[1] == 'x')
            return TRUE;
    }
    return FALSE;
}

int to_hex_range_int(int c) {
    if (c >= '0' && c <= '9')
        return c - '0';       
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return OUT_OF_RANGE;
}

long powr(int num, int x) {
    long sum = 1;
    for (int i = 1; i <= x; ++i)
        sum *= num;
    return sum;
}