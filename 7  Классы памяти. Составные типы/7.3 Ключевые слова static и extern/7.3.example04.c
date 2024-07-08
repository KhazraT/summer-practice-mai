#include <stdio.h>
 
extern int global_var;
extern char global_str[];
 
int main(void) 
{
    printf("global_var = %d\n", global_var);
    puts(global_str);
    return 0;
}
 
char global_str[100] = "Hello";