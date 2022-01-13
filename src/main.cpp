#include <iostream>
#include "../include/qsort.h"

void print_array(int* a, int size)
{
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = { 7, 2, 6, 3, 9, 1, 5, 4 };
    int size = sizeof(a) / sizeof(a[0]);
    int b[size];
    
    print_array(a, size);
    sort::msort(a, b, size);
    print_array(a, size);
    
    return 0;
}
