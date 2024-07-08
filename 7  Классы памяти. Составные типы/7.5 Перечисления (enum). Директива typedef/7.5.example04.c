#include <stdio.h>
 
#define PTR_INT int*
 
typedef int* PTR;
 
int main(void) 
{
    PTR_INT a, b;      // int* a, b;
    PTR ptr_a, ptr_b;  // int *ptr_a, *ptr_b;
    printf("*a = %d, *b = %d\n", *a, *b);
    printf("*ptr_a = %d, *ptr_b = %d\n", *ptr_a, *ptr_b);
 
    return 0;
}