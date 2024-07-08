/*Подвиг 5. Продолжите программу. Необходимо объявить четыре критериальных функции для отбора целочисленных значений при суммировании в функции sum_ar. Все критериальные функции должны иметь сигнатуру:

int <имя функции>(int );
и быть следующими:

is_odd: возвращает 1 для нечетных значений и 0 для четных;
is_positive: возвращает 1 для неотрицательных значений и 0 для отрицательных;
is_negative: возвращает 1 для отрицательных значений и 0 для неотрицательных;
deflt: возвращает 1 для любых значений.
В функции sum_ar реализовать подсчет целых чисел переданного массива ar, для которых критериальная функция (переданная через указатель) возвращает истину (не нулевое значение). Функция sum_ar должна возвращать вычисленную сумму.

В функции main объявить массив указателей с именем funcs на объявленные критериальные функции (в порядке их перечисления в задании). Затем, сформировать массив marks из прочитанных целочисленных значений в количестве не более 20 (необходима проверка на максимальное количество записываемых данных). После этого в операторе switch выполнить подсчет суммы с указанием соответствующей критериальной функции из массива funcs.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.5.5*/
#include <stdio.h>

int is_odd(int num) {
    return num % 2 != 0;
}

int is_positive(int num) {
    return num >= 0;
}

int is_negative(int num) {
    return num < 0;
}

int deflt(int num) {
    return 1;
}

int sum_ar(const int *ar, size_t len_ar, int (*filter)(int)) {
    int sum = 0;
    for (size_t i = 0; i < len_ar; ++i) {
        if (filter(ar[i])) {
            sum += ar[i];
        }
    }
    return sum;
}

int main(void) {
    int (*funcs[])(int) = { is_odd, is_positive, is_negative, deflt };

    int marks[20] = {0};
    int count = 0;
    int item = 0;

    scanf("%d", &item);

    int x;
    while (scanf("%d", &x) == 1 && count < 20) {
        marks[count] = x;
        count++;
    }

    int sum = 0;

    switch (item) {
        case 1:
            sum = sum_ar(marks, count, funcs[0]);
            break;
        case 2:
            sum = sum_ar(marks, count, funcs[1]);
            break;
        case 3:
            sum = sum_ar(marks, count, funcs[2]);
            break;
        default:
            sum = sum_ar(marks, count, funcs[3]);
            break;
    }

    printf("%d\n", sum);

    return 0;
}
