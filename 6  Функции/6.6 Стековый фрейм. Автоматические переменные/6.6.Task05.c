/*Подвиг 5. Продолжите программу. Объявите функцию с именем reverse, которая имеет два параметра (порядок важен):
 - указатель на обрабатываемый массив типа short;
 - число обрабатываемых элементов массива.
Функция reverse должна "переворачивать" переданный массив, то есть, значения должны идти в обратном порядке: от последнего к первому.
Вызовите функцию reverse в функции main для массива digs. Выведите в консоль первые count значений массива digs в одну строчку через пробел.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.6.5*/
#include <stdio.h>
#define MAX_SIZE    20

void reverse(short* ar, int len);
int main(void)
{
    short digs[MAX_SIZE];
    int count = 0;
    while(count < MAX_SIZE && scanf("%hd", &digs[count]) == 1)
        count++;

    // здесь продолжайте функцию main
    reverse(digs, count);
    for (int i = 0; i < count; i++)
        printf("%d ", digs[i]);

    return 0;
}
void reverse(short* ar, int len){
    short temp;
    
    for (int i = 0; i < len/2; i++){
        temp = ar[i];
        ar[i] = ar[len - 1 - i];
        ar[len - 1 - i] = temp;
    }
}