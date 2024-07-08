#include <stdio.h>
char name[] = "Variables";
int global_var_1 = 5;
int global_var_2 = 5 * 7;
int global_var_3 = sizeof(name) + 1;
 
int main(void) 
{
    int a = 1;
    int b = a * 2 + global_var_2;
    int size = global_var_3 * 10;
 
    return 0;
}