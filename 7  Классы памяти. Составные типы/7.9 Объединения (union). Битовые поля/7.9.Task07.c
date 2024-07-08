/*Подвиг 7. Объявите в программе перечисление с типом TYPE_PARAM и константами param_int, param_double; объявите объединение с типом DATA и полями data_i (тип int), data_d (тип double). Объявление делается подобно примеру из предыдущего подвига. Затем, объявите функцию с именем sum_ar с набором параметров (порядок важен):

массив элементов типа DATA;
число элементов переданного массива (тип size_t);
тип данных в массиве (тип TYPE_PARAM).
Функция sum_ar должна вычислять сумму значений элементов массива в зависимости от типа данных. Если тип параметра равен константе param_int, то значения берутся из поля data_i объединения DATA, иначе - из поля data_d. Функция sum_ar должна сохранять вычисленную сумму в соответствующее поле переменной типа DATA (объединение) и возвращать его (через копирование).

В функции main вызовите функцию sum_ar для суммирования целочисленных значений 1, 2, 3, 4, 5 и еще раз вызовите для вещественных 1.1, 2.2, 3.3, 4.4, 5.5. Результат сохраните в переменных res_1 и res_2 типа DATA в соответствующих полях.

Подумайте, как можно сразу создать анонимный объект-массив из элементов DATA с нужными значениями элементов в момент вызова функции sum_ar (то есть, заранее массивы можно не создавать).

P. S. В консоль ничего выводить не нужно.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 5

typedef enum {param_int, param_double} TYPE_PARAM;

typedef union data{
    int data_i;
    double data_d;
} DATA;

typedef struct {
    DATA data;
    TYPE_PARAM type;
} OBJ;

DATA sum_ar(DATA ar[], size_t len_ar, TYPE_PARAM type)
{
    DATA *s = malloc(sizeof(DATA));

    switch(type){
        case param_int:
            s->data_i = 0;
            for(int i = 0; i < len_ar; ++i)
                s->data_i += ar[i].data_i;
            break;
        case param_double:
            s->data_d = 0.0;
            for(int i = 0; i < len_ar; ++i)
                s->data_d += ar[i].data_d;
    }
    DATA res = *s;
    return res;
}

int main(void)
{
    DATA res_1 = sum_ar((DATA[]){(DATA){.data_i = 1}, (DATA){.data_i = 2}, (DATA){.data_i = 3}, (DATA){.data_i = 4}, (DATA){.data_i = 5}}, MAX_LEN, param_int);

    DATA res_2 = sum_ar((DATA[]){{.data_d = 1.1}, (DATA){.data_d = 2.2}, (DATA){.data_d = 3.3}, (DATA){.data_d = 4.4}, (DATA){.data_d = 5.5}}, MAX_LEN, param_double);

    return 0;
}