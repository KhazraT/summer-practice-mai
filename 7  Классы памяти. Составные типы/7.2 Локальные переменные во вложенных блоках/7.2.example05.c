#include <stdio.h>
 
int main(void) 
{
    int t = 33;
 
    for(int t = 0; t < 3; ++t) {
        printf("t = %d\n", t);
    }
 
    printf("main: t = %d\n", t);
 
    return 0;
}