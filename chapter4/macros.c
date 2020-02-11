#include <stdio.h>

#define swap(t,x,y) { \
    t temp = x;       \
    x = y;            \
    y = temp;         \
}

void swap_a(int *a, int *b);

int main() {
    int a, b;
    a = 5;
    b = 10;

    printf("a: %d  b: %d\n", a, b);
    swap(int,a,b);
    printf("a: %d  b: %d\n", a, b);
    
    swap_a(&a,&b);
    printf("a: %d  b: %d\n", a, b);

    return 0;
}

void swap_a(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}