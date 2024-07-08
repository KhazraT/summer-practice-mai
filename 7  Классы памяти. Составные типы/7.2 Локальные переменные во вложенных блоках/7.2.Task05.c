/*Подвиг 5 (на повторение). Напишите программу, которая читает из входного потока натуральное число n. Необходимо найти все делители этого числа (то есть, натуральные числа, которые нацело делят число n, начиная с 1). Все найденные делители вывести по порядку (начиная с наименьшего) в одну строчку через пробел.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/7.2.5*/
#include <stdio.h>

int main(void)
{
    int var;

    scanf("%d", &var);
    
    for (int i = 1; i <= var; i++)
        if(var % i == 0)
            printf("%d ", i);

    return 0;
}