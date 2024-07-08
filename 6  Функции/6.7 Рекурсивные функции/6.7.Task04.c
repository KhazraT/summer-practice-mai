/*Подвиг 4. Продолжите программу. Объявите рекурсивную функцию со следующей сигнатурой:

int sum_ar(const short* ar, size_t len, size_t indx);
которая вычисляет сумму значений элементов переданного массива ar и возвращает вычисленное значение.

Вспомогательный параметр indx (с начальным значением 0) служит для перебора элементов массива ar при рекурсивном вызове функции sum_ar.

В функции main вызовите функцию sum_ar и выведите в консоль возвращенной ей значение в виде целого числа.

P. S. В теле функции sum_ar не использовать какие-либо операторы циклов.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.7.4*/
#include <stdio.h>
#define MAX_LENGTH    20

int sum_ar(const short* ar, size_t len, size_t indx);

int main(void)
{
    short ar[MAX_LENGTH] = {6, 4, 10, -43, 24, 76, 100, -55, 2};
    int count = 0;
    while(count < MAX_LENGTH && scanf("%hd", &ar[count]) != EOF)
        count++;
    printf("%d", sum_ar(ar, count, 0));
    return 0;
}

int sum_ar(const short *ar, size_t len, size_t indx) {
    int sum = 0;
    if(indx < len) {
       sum += ar[indx];
       return sum + sum_ar(ar, len, ++indx);
    }
    return sum;  
}
