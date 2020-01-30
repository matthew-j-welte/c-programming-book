#include <stdio.h>

int binary_search_1(int x, int v[], int n);
int binary_search_2(int x, int v[], int n);

int main() {
    int size = 2000000;
    int nums[size];
    for (int i = 0; i < size; ++i)
        nums[i] = i;
    
    printf("%d\n", binary_search_2(83400, nums, size));
    return 0;
}

int binary_search_1(int x, int v[], int n) {
    int low,high,mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binary_search_2(int x, int v[], int n) {
    int low,high,mid;

    low = 0;
    high = n - 1;
    while (low <= high && x != v[mid]) {
        if (x > v[mid])
            low = mid + 1;
        else
            high = mid - 1;
        mid = (low+high) / 2;
    }
    if(x==v[mid])
        return mid;
    return -1;
}