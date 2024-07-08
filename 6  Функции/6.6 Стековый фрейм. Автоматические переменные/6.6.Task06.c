/*Подвиг 6. Продолжите программу. Объявите функцию с именем strip_str, которая имеет следующие параметры (порядок важен):
 - указатель на обрабатываемую корректную Си-строку;
 - указатель на строку с удаляемыми символами.
Функция strip_str должна из переданной ей строки удалить все символы, указанные в последнем параметре (строке с удаляемыми символами). Например, если указана строка "!? &@", то все эти символы, где бы они в строке ни находились и в каком бы порядке ни шли, следует удалить.

В функции main вызовите функцию strip_str для строки str и укажите удалить из нее символы ".,-!?". Выведите полученную строку в консоль.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.6.6*/
#include <stdio.h>
#include <string.h>

char* strip_str( char *str, char *find )
{   char *ptr;
    while( ptr = strpbrk( str, find ) ) 
        strcpy( ptr, ptr + 1 );
    
    return str;
}

int main(void)
{
    char str[100] = {0}, str2[20];
    fgets(str, sizeof(str)-1, stdin);
    char* ptr_n = strrchr(str, '\n');
    if(ptr_n != NULL)
        *ptr_n = '\0';

    printf( strip_str(str, ".,-!?") );

    return 0;
}