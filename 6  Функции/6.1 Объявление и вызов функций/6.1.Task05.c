/*Подвиг 5. В программе ниже объявите функцию с именем get_volume, которая принимает три целочисленных значения h, w, d и вычисляет объем h * w * d. Вычисленное значение возвращается функцией. Прочитайте из входного потока три целых числа, записанных в одну строчку через пробел в переменные height, width, depth. Вызовите в функции main функцию get_volume с аргументами height, width, depth. Результат сохраните в переменной и выведите ее значение в консоль как одно целое число.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.1.5*/
#include <stdio.h>

int get_volume(int h, int w, int d)
{
    return h * w * d;
}

int main(void)
{
    int height, width, depth;
    scanf("%d %d %d", &height, &width, &depth);
    int res = get_volume(height, width, depth);

    printf("%d\n", res);

    return 0;
}