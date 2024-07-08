/*Подвиг 2. Продолжите программу. Необходимо объявить рекурсивную функцию с именем recursive и одним целочисленным параметром, которая бы выводила в консоль в одну строчку через пробел целые числа в диапазоне от MAX_RECURSION до 1 (включительно).

P. S. В теле функции recursive не использовать какие-либо операторы циклов.*/
#include <stdio.h>
#define MAX_RECURSION    4

void recursive(int n);

int main(void)
{
    recursive(1);

    return 0;
}

void recursive(int n){
    if (n != MAX_RECURSION)
        recursive(n+1);
    printf("%d ", n);
}