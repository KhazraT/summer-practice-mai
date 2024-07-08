/*файл module.c:
#include <stdlib.h>
 
int global_seed_randint = 0;
 
int randint(int a, int b)
{
    int right = a, left = b;
    if(a > b) {
        right = b;
        left = a;
    }
 
    return rand() % (left - right + 1) + right;
}*/
#include <stdio.h>
 
extern int global_seed_randint;
int randint(int a, int b);
 
int main(void) 
{
    int a = 1, b = 10;
 
    printf("global_seed_randint = %d\n", global_seed_randint);
    printf("%d\n", randint(a, b));
    printf("%d\n", randint(a, b));
    printf("%d\n", randint(a, b));
 
    return 0;
}