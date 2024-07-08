#include <stdio.h>
 
int main(void) 
{
    int a = 1;
 
    {
        int b = 2;
        printf("a = %d, b = %d\n", a, b);
    }
 
    printf("a = %d\n", a);
 
    return 0;
}