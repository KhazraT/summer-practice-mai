/*Подвиг 9 (с повторением). Напишите программу, которая в функции main читает из входного потока слова (разделены пробелом). Максимальное количество слов не более 20, а максимальная длина каждого слова не более 50 символов.

Объявите функцию со следующей сигнатурой:

int is_correct(const char* str);
Функция is_correct должна проверять, что в строке содержится фрагмент "ra" без учета регистра. Если это так, то она возвращает 1, иначе 0. Определите на эту функцию указатель нового типа FUNC_CORRECT (тип данных).

Объявите еще одну функцию с сигнатурой:

int get_correct_words(const char (*words)[50], int count_words, FUNC_CORRECT filter);
Функция get_correct_words должна подсчитывать количество корректных слов (для которых is_correct возвращает 1) в массиве words и возвращать вычисленное значение.

В функции  main (для прочитанных из входного потока слов) вызовите функцию get_correct_words с фильтром is_correct и выведите в консоль число корректных слов.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/7.5.9*/
#include <stdio.h>
#include <string.h>

int is_correct(const char* str);
typedef int (*FUNC_CORRECT)(char*);
int get_correct_words(const char (*words)[50], int count_words, FUNC_CORRECT filter);

int main(void){
    char str[20][50];
    int cnt = 0;
    
    FUNC_CORRECT foo_ptr = is_correct;
    
    while(scanf("%s", str[cnt]) == 1){
        cnt++;
    }
    
    int res = get_correct_words(str, cnt, foo_ptr);
    printf("%d", res);

    return 0;
}

int is_correct(const char* str){
    char temp[50];
    int i = 0;
    
    strcpy(temp, str);
    while(temp[i]){
        temp[i] = tolower(temp[i]);
        i++;
    }
    return strstr(temp, "ra") != NULL;
}

int get_correct_words(const char (*words)[50], int count_words, FUNC_CORRECT filter){
    int cnt = 0;
    for (int i = 0; i < count_words; i++)
        if (filter(words[i]))
            cnt++;
    
    return cnt;
}