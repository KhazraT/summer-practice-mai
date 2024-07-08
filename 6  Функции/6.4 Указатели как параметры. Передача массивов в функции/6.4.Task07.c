/*Подвиг 7. Продолжите программу. Объявите функцию с именем show_pole, которой передается двумерный массив типа char размером SIZE x SIZE элементов. Она должна отобразить в консоли этот двумерный массив в виде таблицы размером SIZE x SIZE по следующей схеме:
* * *
* * *
* * *
То есть, в три строки и три столбца. Причем, между символами в строках должен быть один пробел. В конце строк пробела быть не должно.

Вместо символа '*'' необходимо вывести символ, который хранится в элементах переданного массива, либо символ '#', если значение элемента равно 0 (целое число).

В функции main вызывать функцию show_pole для массива pole.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.4.7*/
#include <stdio.h>

#define SIZE 3

void show_pole(char pole[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (pole[i][j] == 0) {
                printf("#");
            } else {
                printf("%c", pole[i][j]);
            }
            if (j < SIZE - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(void) {
    char pole[SIZE][SIZE] = {0};
    int temp;
    int count = 0;
    while(count < SIZE * SIZE && scanf("%d", &temp) == 1) {
        char* ptr_p = &pole[0][0] + count;
        *ptr_p = (temp == 1) ? 'x' : (temp == 2) ? 'o' : 0;
        count++;
    }

    show_pole(pole);

    return 0;
}
