#include<iostream>
using namespace std;
 
void show_args(short a=10, double b=20.0, int c=30) 
{
         printf("a = %d, b = %.2f, c = %d\n", a, b, c);
}
 
int main() {
         show_args();
         show_args(1);
         show_args(1, 2);
         show_args(1, 2, 3);
 
         return 0;
}