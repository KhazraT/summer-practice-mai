#include <stdio.h>
#include <math.h>
 
double sq4_x(double x)
{
         if(x < 0)
                   return NAN;
 
         return pow(x, 0.25);
}
 
int main(void) 
{
         printf("%f\n", sq4_x(16));
         return 0;
}