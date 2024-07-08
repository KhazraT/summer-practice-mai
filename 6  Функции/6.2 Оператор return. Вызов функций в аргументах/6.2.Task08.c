/*Подвиг 8. Напишите программу, которая читает из входного потока два целых числа в переменные x, y, записанных в одну строчку через пробел. Объявите функцию с именем get_length, которая возвращает длину радиус-вектора с координатами (x, y).
Напомню, что длина радиус-вектора вычисляется по формуле:
𝑙𝑒𝑛𝑔𝑡ℎ=квадратный_корень(x^2+y^2) 
В функции main вызовите функцию get_length с прочитанными значениями x, y и выведите в консоль длину радиус-вектора с точностью до сотых.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.2.8*/
#include <stdio.h>
#include <math.h>

double get_length(int a, int b){
    return sqrt((pow((double)a, 2) + pow((double)b, 2)));
}

int main(void)
{
    // здесь продолжайте функцию main
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%.2f", get_length(a, b));
    return 0;
}