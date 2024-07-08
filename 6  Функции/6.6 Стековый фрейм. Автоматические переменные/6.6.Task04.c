/*Подвиг 4 (продолжение подвига 3). Дополнительно к функции norm из предыдущего подвига объявите еще одну функцию с сигнатурой:
double reley(double x1, double x2);
которая генерирует псевдослучайное число по формуле:
​y=квадратный_корень(x1^2+x2^2)
где x1, x2 - псевдослучайные числа, вычисленные (сгенерированные) функцией norm.
В функции main вызовите функцию reley и в аргументах запишите вызов функции norm c аргументами 0, 5. Сохраните возвращенное значение функцией reley в вещественной переменной y (игрек).
P. S. В консоль ничего выводить не нужно.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


double norm(int , int);
double reley(double , double);

int main(void)
{
    double y = reley(norm(0, 5), norm(0, 5));
    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}

double norm(int a, int b)
{
    srand(time(NULL));
    int N = 100;
    double sum = 0.0;

    int nums;
    for(int i = 0; i < N; ++i){
        nums = rand() % (b - a) + a;
        sum += nums;
    }
    sum /= N;
    return sum;
}

double reley(double x1, double x2)
{
    return pow(x1 * x1 + x2 * x2, 0.5);
}