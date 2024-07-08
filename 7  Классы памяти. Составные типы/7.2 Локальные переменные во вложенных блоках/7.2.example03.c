#include <stdio.h>
 
int main(void) 
{
    int a = 1, b = 3;
    int t = a + b;
 
    if(a < b) 
    {
        int t = a;
        a = b;
        b = t;
    }
 
    printf("a = %d, b = %d, t = %d\n", a, b, t);
 
    return 0;
}