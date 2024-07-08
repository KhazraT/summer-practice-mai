/*Подвиг 8. Продолжите программу. Объявите функцию с именем is_win, которой передается двумерный массив типа char размером SIZE x SIZE элементов. Функция is_win должна проверять и возвращать статус переданного игрового поля игры "Крестики-нолики" в виде целого числа:

0 - игра не окончена;
1 - выиграли "крестики";
2 - выиграли "нолики";
3 - ничья.

Каждый элемент переданного двумерного массива хранит либо символ 'x', либо символ 'o', либо целое число 0, если клетка свободна.

В функции main вызовите функцию is_win для массива pole. Выведите в консоль вычисленный статус игрового поля в виде целого числа.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.4.8*/
#include <stdio.h>

#define SIZE 3

int is_win(char pole[SIZE][SIZE]) {
    // Проверка строк
    for (int i = 0; i < SIZE; i++) {
        if (pole[i][0] == pole[i][1] && pole[i][1] == pole[i][2]) {
            if (pole[i][0] == 'x') return 1;
            if (pole[i][0] == 'o') return 2;
        }
    }
    
    // Проверка столбцов
    for (int j = 0; j < SIZE; j++) {
        if (pole[0][j] == pole[1][j] && pole[1][j] == pole[2][j]) {
            if (pole[0][j] == 'x') return 1;
            if (pole[0][j] == 'o') return 2;
        }
    }
    
    // Проверка диагоналей
    if (pole[0][0] == pole[1][1] && pole[1][1] == pole[2][2]) {
        if (pole[0][0] == 'x') return 1;
        if (pole[0][0] == 'o') return 2;
    }
    
    if (pole[0][2] == pole[1][1] && pole[1][1] == pole[2][0]) {
        if (pole[0][2] == 'x') return 1;
        if (pole[0][2] == 'o') return 2;
    }

    // Проверка на ничью или продолжение игры
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (pole[i][j] == 0) {
                return 0;  // игра не окончена
            }
        }
    }

    return 3;  // ничья
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

    int status = is_win(pole);
    printf("%d\n", status);

    return 0;
}
