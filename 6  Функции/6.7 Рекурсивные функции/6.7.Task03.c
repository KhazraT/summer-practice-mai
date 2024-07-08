/*Подвиг 3. Продолжите программу. Необходимо объявить рекурсивную функцию со следующей сигнатурой:

size_t range_to_ar(int* ptr_a, size_t max_len, int from, int to, size_t count);
Эта функция должна последовательно заносить в переданный массив (через указатель ptr_a) целые числа в диапазоне [from; to] (включая границы) с шагом 1, не превышая длину массива max_len. Функция range_to_ar возвращает число count - записанных в массив значений (не более max_len).

В функции main выведите в консоль в одну строчку через пробел первые cnt значений массива ar.

P. S. В теле функции range_to_ar не использовать какие-либо операторы циклов.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.7.3*/
#include <stdio.h>
#define MAX_LENGTH    20
size_t range_to_ar(int* ptr_a, size_t max_len, int from, int to, size_t count);


int main(void)
{
    int max_rec;
    int ar[MAX_LENGTH];
    scanf("%d", &max_rec);

    size_t cnt = range_to_ar(ar, MAX_LENGTH, 1, max_rec, 0);

    for(int i = 0; i < cnt; i++) {
        printf("%d ", ar[i]);
    }

    return 0;
}

size_t range_to_ar(int* ptr_a, size_t max_len, int from, int to, size_t count) {
    if(from > max_len || from > to) return 0;

    ptr_a[count++] = from++;

    return 1 + range_to_ar(ptr_a, max_len, from, to, count);
}