/*Подвиг 4. Напишите программу, которая читает из входного потока в массив несколько вещественных значений (не менее одного и не более 20), записанных в одну строчку через пробел. Объявите функцию с именем to_csv и следующими параметрами (порядок параметров должен соблюдаться):

 - указатель на массив символов (корректную C-строку);
 - массив вещественных чисел (тип double);
 - длина массива (неотрицательное целое число).
Функция to_csv должна из переданного ей массива вещественных чисел сформировать строку в формате:

"csv: <число 1>; <число 2>; ...; <число N>"

Точность вещественных чисел должна быть два знака после запятой (точки), то есть, до сотых. Например:

"csv: 0.56; -65.43; 0.10; 11.00"

Полагается, что длины строки в 100 символов достаточно для хранения сформированной строки из чисел.

Функция to_csv должна возвращать количество (целое число) записанных в строку вещественных чисел.

В функции main вызвать функцию to_csv для вещественных чисел, прочитанных из входного потока и вывести в консоль сформированную строку.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.4.4*/
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 20
#define MAX_SIZE_STR 100

int to_csv(char *str, int str_size, double *data, int data_size)
{
    char buf[MAX_SIZE_STR];
    int cnt = 0;

    sprintf(str, "csv: ");
    for (int i = 0; i < data_size; i++)
    {
        if (i != data_size - 1)
            sprintf(buf, "%.2f; ", data[i]);
        else
            sprintf(buf, "%.2f", data[i]);
        
        strcat(str, buf);
        cnt++;
    }

    return cnt;
}

int main()
{
    char str[MAX_SIZE_STR];
    double array[MAX_SIZE];
    int size = 0;
    while(scanf("%lf", array + size) == 1) size++;
    to_csv(str, MAX_SIZE_STR, array, size);
    printf("%s", str);
    return 0;
}
