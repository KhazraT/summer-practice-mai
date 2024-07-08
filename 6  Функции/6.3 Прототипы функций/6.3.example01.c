#include <stdio.h>
 
double per_sq(double w, double h);
 
int main(void) 
{
         printf("per = %.2f\n", per_sq(2.5, 3.5));
         return 0;
}
 
double per_sq(double w, double h)
{
         if(w < 0 || h < 0)
                   return 0;
 
         return 2 * (w + h);
}