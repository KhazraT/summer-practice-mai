#include <stdio.h>
#include <math.h>
 
double sq4_x(double x)
{
         if(x < 0)
                   return NAN;
 
         return pow(x, 0.25);
}

void print_even_x(int x)
{
         if(x % 2 != 0)
                   return;
 
         printf("x = %d\n", x);
}

int main(void) 
{
         printf("%f\n", sq4_x(-16));
         print_even_x(4);
 
         return 0;
}