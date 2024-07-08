#include <stdio.h>

char name[] = "Variables";  /* в секции .data */
double big_ar[1000000];     /* в секции .bss */
 
int main(void) 
{
    int var_main; /* автоматическая локальная переменная */
    return 0;
}