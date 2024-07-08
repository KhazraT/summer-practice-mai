#include <stdio.h>
#include <math.h>
 
double min_2(double a, double b)
{
         return (a < b) ? a : b;
}

double min_3(double a, double b, double c)
{
         double min_ab = min_2(a, b);
         return (min_ab < c) ? min_ab : c;
}

int main(void) 
{
         int x = 1, y = -2, z = 10;
 
         double res_1 = min_2(x, y);
         double res_2 = min_3(x, y, z);
         double res_3 = min_2(min_2(x, y), z);
         double res_4 = min_2(x, min_2(y, z));
 
         printf("res_1 = %.2f, res_2 = %.2f, res_3 = %.2f, res_4 = %.2f\n", 
                      res_1, res_2, res_3, res_4);

        double r4 = min_2(min_2(-2, 3), min_2(x, y));
        double r5 = min_2(min_2(-2, 3), min_3(x, y, z));

         return 0;
}