#include <stdio.h>

void swap_2(int* a, int* b)
{
         int t = *a;
         *a = *b;
         *b = t;
}

int main(void) 
{
         short var_a = 10;
         short* ptr = &var_a;
         *ptr = 5;
        
        int x = 5, y = 10;
         swap_2(&x, &y);

         return 0;
}