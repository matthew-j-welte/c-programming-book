#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned clear_range(unsigned x, int begin, int end);
unsigned rightrot(int x, int n);
int bitcount(unsigned x);

int main() {
    printf("%u\n", setbits(20, 4, 2, 7));
    printf("%u\n", invert(20, 2, 3));
    printf("%u\n", bitcount(23));
    printf("%u\n", bitcount(0));
    return 0;
}

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned y_bits = getbits(y, n, n);
    unsigned cleared_x = clear_range(x,p,n);
    unsigned bits_to_add = (y_bits << (p-n+1));
    return (cleared_x ^ bits_to_add);
}

unsigned invert(unsigned x, int p, int n) {
    unsigned inverted_range = getbits(~x, p, n);
    unsigned cleared_x = clear_range(x, p, n);
    unsigned bits_to_add = (inverted_range << (p-n+1));
    return (cleared_x ^ bits_to_add);

}

unsigned clear_range(unsigned x, int begin, int end) {
    unsigned bit_range_clear = (~0 << begin+1) ^ ~(~0 << (begin-end+1));
    return x & bit_range_clear; // The range being replaced should now be zeroed out
}

unsigned rightrot(int x, int n) {
    return x >> n;
}

int bitcount(unsigned x) {
    int count;
    for(count = 0; x != 0; x&= (x-1))
        ++count;
    return count;
}