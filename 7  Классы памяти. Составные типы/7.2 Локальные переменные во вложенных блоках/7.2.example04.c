#include <stdio.h>
 
int main(void) 
{
    int t = 3;
 
    while(t-- > 0) {
        int t = 10;
        t--;
        printf("t = %d\n", t);
    }
 
    printf("main: t = %d\n", t);
 
    return 0;
}