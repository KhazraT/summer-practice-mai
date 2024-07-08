/*Подвиг 8. Продолжите программу. Необходимо объявить функцию со следующей сигнатурой:

void* expand_array(short* ptr, size_t* len, short fill);
Здесь *len - длина массива (число его элементов). Данная функция должна удваивать размер области памяти, выделенной под указатель ptr, в новую область копировать прежние данные, а остальные заполнять значениями fill. Прежняя область должна освобождаться (если была выделена новая). Значение размера *len нужно также увеличить в два раза. В конце функция expand_array должна вернуть адрес удвоенной области памяти.

В функции main вызовите функцию expand_array для удвоения памяти, на которую ведет указатель ptr_d, и значением fill = -1. В результате указатель ptr_d должен ссылаться на удвоенную область памяти. Затем, через указатель ptr_d выведите в консоль в одну строчку через пробел все целые числа типа short, хранящиеся в удвоенной области памяти.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/7.4.8*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL   10

// здесь объявляйте функцию
void* expand_array(short* ptr, size_t* len, short fill);

int main(void)
{
   short * ptr_d = calloc(TOTAL,  sizeof(short));
   size_t len = TOTAL;
   if(ptr_d == NULL)
        return 0;

    int count = 0;
    while(count < TOTAL && scanf("%hd", &ptr_d[count]) == 1)
        count++;

    // здесь продолжайте функцию main
    ptr_d = expand_array(ptr_d, &len, -1);
    
    for (int i = 0; i < len; i++)
        printf("%d ", ptr_d[i]);

    free(ptr_d);
}

void* expand_array(short* ptr, size_t* len, short fill){
    short* new_ptr = malloc(*len * sizeof(short) * 2);
    for (int i = 0; i < *len * 2; i++)
        new_ptr[i] = fill;
    
    memcpy(new_ptr, ptr, *len * sizeof(short));
    free(ptr);
    ptr = new_ptr;
    *len *= 2;
    
    return ptr;
}