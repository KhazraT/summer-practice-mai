/*Подвиг 9. Продолжите программу. Объявите функцию со следующей сигнатурой:

char * merge_string(const char* str1, const char* str2);
Данная функция должна выделить память под новую строку так, чтобы в нее помещались все символы первой (str1) и второй (str2) строк. Затем, в новую строку скопировать сначала содержимое первой строки (только символы строки), а следом за ней содержимое второй строки. В конце не забудьте добавить символ '\0', чтобы сформировать корректную Си-строку. После объединения функция merge_string должна вернуть адрес сформированной строки.

В функции main вызовите функцию merge_string для объединения строк str_1 и str_2 (именно в таком порядке). Выведите в консоль полученную строку.

P. S. Не забудьте в конце программы освободить выделенную память.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/7.4.9*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * merge_string(const char* str1, const char* str2);

void getline(char *buffer, size_t max_len)
{
    fgets(buffer, max_len - 1, stdin);
    char *ptr_n = strrchr(buffer, '\n');
    if(ptr_n)

        *ptr_n = '\0';
}

int main(void)
{
    char str1[200] = {0};
    char str2[200] = {0};

    getline(str1, sizeof(str1));
    getline(str2, sizeof(str2));

    char *new_str = merge_string(str1, str2);
    if(new_str == 1)
        return 1;

    puts(new_str);
    return 0;
}

char * merge_string(const char* str1, const char* str2)
{
    int cnt_1 = sizeof(str1), cnt_2 = sizeof(str2);

    char *ptr = calloc(cnt_1 + cnt_2 + 1, sizeof(char));
    if(ptr == NULL)
        return 1;

    strcpy(ptr, str1);
    strcat(ptr, str2);
    return ptr;
}