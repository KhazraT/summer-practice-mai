/*Подвиг 5. Допишите программу. Объявите функцию с именем get_data_csv со следующими параметрами (порядок параметров должен соблюдаться):

 - массив вещественных чисел (double);
 - максимальная длина массива (неотрицательное целое число);
 - указатель на корректную Си-строку.
Функция get_data_csv должна из переданной ей строки выделять и сохранять в переданный массив вещественные числа, которые записаны в формате:

"csv: <число 1>; <число 2>; ...; <число N>"

Например:

"csv: 0.56; -65.43; 0.1; 11.0"

Необходимо выделенные числа сохранять в переданном массиве в количестве не превышающем длину массива 20 элементов. Функция get_data_csv должна возвращать количество (целое число) записанных в массив вещественных чисел.

В функции main вызвать функцию get_data_csv для строки str и вывести в консоль выделенные в массив вещественные числа в одну строчку через пробел с точностью до сотых.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.4.5*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 20

int get_data_csv(double *ar, int max_length, char *str)
{
    int length = 0;
    while (((str = strchr(str, ' ')) != NULL) && (length < max_length))
    {
        ar[length] = atof(str);
        length++;
        str++;
    }
    return length;
}

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    double ar[MAX_LENGTH] = {0};
    int length = get_data_csv(ar, MAX_LENGTH, str);

    for (int i = 0; i < length; i++)
        printf("%.2f ", ar[i]);

    return 0;
}