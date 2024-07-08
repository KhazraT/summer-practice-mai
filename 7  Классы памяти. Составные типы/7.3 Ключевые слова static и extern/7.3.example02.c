#include <stdio.h>

int main(void) 
{
    int var_main;           /* автоматическая локальная переменная */
    static short var_st;   /* локальная статическая переменная */
    printf("var_main = %d, var_st = %d\n", var_main, var_st);
    return 0;
}