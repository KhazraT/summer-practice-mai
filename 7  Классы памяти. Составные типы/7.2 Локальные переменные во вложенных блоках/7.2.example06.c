#include <stdio.h>
 
int main(void) 
{
    int p = 1;
    int n = 7;
 
    for(register int i = 2; i <= n; ++i)
        p *= i;
 
    return 0;
}