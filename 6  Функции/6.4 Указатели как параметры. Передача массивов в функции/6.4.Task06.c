/*Подвиг 6. Продолжите программу. Необходимо объявить функцию с именем transpose, которой передается двумерный массив размером SIZE x SIZE из чисел типа short. Функция transpose должна строки заменять на соответствующие столбцы (транспонирование) переданного массива. В функции main вызовите функцию transpose для массива matrix. Выведите полученный транспонированный массив matrix в консоль в виде таблицы целых чисел SIZE x SIZE элементов.

(Обратите внимание, что между числами в строках должен быть один пробел, а в конце строк - ни одного.) 

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.4.6*/
#include <stdio.h>

#define SIZE    4

void transpose(short matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            short temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

int main(void) {
    short matrix[SIZE][SIZE] = {0};
    short* ptr = &matrix[0][0];
    int count = 0;
    while(count < SIZE * SIZE && scanf("%hd", ptr) == 1) {
        ptr++;
        count++;
    }

    transpose(matrix);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%hd", matrix[i][j]);
            if (j < SIZE - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
