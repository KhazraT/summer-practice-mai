#include<iostream>
using namespace std;
 
int modul(int x) 
{
         return (x < 0) ? -x : x;
}
 
double modul(double x) 
{
         return (x < 0) ? -x : x;
}
 
int main(void) {
         int a1 = modul(-3);
         int a2 = modul(-3.5);
         double a3 = modul(-3);
         double a4 = modul(-3.5);
 
         return 0;
}