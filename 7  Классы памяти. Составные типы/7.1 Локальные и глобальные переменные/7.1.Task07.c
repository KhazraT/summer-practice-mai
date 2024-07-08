/*Подвиг 7 (на повторение). Продолжите программу. В функции main из стандартного входного потока читаются целые числа. Необходимо все их сохранять в массиве marks (не более 20). То есть, чисел может быть и больше 20, но сохранять только первые 20 в порядке их считывания. 

Допишите функцию mean_ar, которая бы вычисляла среднее арифметическое чисел переданного ей массива ar. Учитывать при вычислении следует только те числа, для которых переданная функция (через указатель) с сигнатурой:

int <имя функции>(int);
возвращает истину (не нулевое значение). Полученное значение должно возвращаться функцией mean_ar.

В функции main вызовите функцию mean_ar для массива marks, обрабатывая только числа от 1 до 5 включительно (проверка выполняется дополнительной, вспомогательной функцией, которая, затем, передается последним аргументом в функцию mean_ar). Выведите в консоль вещественное значение с точностью до десятых, которое вернула функция mean_ar.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/7.1.7*/
#include <stdio.h>

#define MAX 20

double mean_ar(const int *ar, size_t len_ar, int (*is_correct)(int))
{
    int sum = 0;
    int j = 0;
    for(int i = 0; i < len_ar; ++i)
        if(is_correct(ar[i])){
            sum += ar[i];
            j++;
        }
            

    return (double) sum / j;
}

int one_to_five(int num)
{
    return num >= 1 && num <= 5;
}

int main(void)
{
    int marks[MAX] = {0};
    int cnt = 0;
    while(scanf("%d", &marks[cnt]) == 1 && cnt < MAX) 
        cnt++;

    double m = mean_ar(marks, cnt, one_to_five);
    printf("%.1f\n", m);

    return 0;
}