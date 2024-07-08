#include <stdio.h>
 
int main(void) 
{
    int a = 1, b = 3;
 
    if(a < b) 
    {
        int t = a;
        a = b;
        b = t;
    }
 
    printf("a = %d, b = %d\n", a, b);
 
    return 0;
}