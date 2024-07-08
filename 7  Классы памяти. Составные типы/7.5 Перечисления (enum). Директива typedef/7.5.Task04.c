/*Подвиг 4. Напишите программу, в которой объявляется перечисление с идентификатором menu_item и константами:

item_exit = 1, item_c = 2, item_python = 3, item_java = 4

В функции main прочитайте из входного потока целочисленное значение и сравните его с одной из констант перечисления. Сравнение следует выполнить с помощью оператора switch. При совпадениях в консоль выведите следующие строки (без кавычек):

item_exit: "Выход";
item_c: "Язык Си";
item_python: "Язык Python";
item_java: "Язык Java".

Если ни одна из констант не была выбрана, то вывести строку:

"Не верный пункт меню"*/
#include <stdio.h>

enum menu_item{item_exit = 1, item_c = 2, item_python = 3, item_java = 4} items;

int main()
{
    
    int key;
    scanf("%d", &key);
    switch(key) {
    case item_exit:
        puts("Выход");
        break;
    case item_c:
        puts("Язык Си");
        break;
    case item_python:
        puts("Язык Python");
        break;
    case item_java:
        puts("Язык Java");
        break; 
        default: puts("Не верный пункт меню");
    }

    return 0;
}