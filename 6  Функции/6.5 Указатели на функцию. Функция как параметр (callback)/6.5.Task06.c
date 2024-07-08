/*Подвиг 6* (с повторением). Продолжите программу. Необходимо дописать функцию sort_string, которая бы выполняла сортировку символов переданной строки str (только символов строки, а не всех символов массива) по их возрастанию (неубыванию). Критерий возрастания (какой символ считать большим, а какой меньшим) задается дополнительной функцией с сигнатурой:

int match_ab(const char a, const char b);
Данная функция должна возвращать 1, если a < b, и 0 в противном случае. И, кроме того, все цифровые символы ('0', ..., '9') должны быть "меньше" любых других символов. То есть, при сортировке сначала в строке будут идти цифровые символы (по возрастанию), а затем все остальные (по возрастанию).

Вызовите функцию sort_string для строки str и с функцией сравнения match_ab. Выведите полученную строку str в консоль.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.5.6*/
#include <stdio.h>
#include <string.h>

int match_ab(const char a, const char b)
{
    if (a == ' ') // "костыль" что бы пробел был после цифр ':'
       return a + 25 > b;
    if (b == ' ') // "костыль" что бы пробел был после цифр ':'
       return a > b + 25;    
    return a > b;
}


void sort_string(char *str, size_t max_len, int (*sort_char) (char, char))
{
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        int min_indx = i;
        for (int j = i + 1; j < len; j++) {
            if (sort_char(str[min_indx], str[j]))
                min_indx = j;               
                }
        if (i != min_indx) {
            char tmp = str[i];
            str[i] = str[min_indx];
            str[min_indx] = tmp;
            
        }
    }
}

int main(void)
{
    char str[100] = {0};
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    sort_string(str, sizeof(str), match_ab);
    puts(str);

    return 0;
}