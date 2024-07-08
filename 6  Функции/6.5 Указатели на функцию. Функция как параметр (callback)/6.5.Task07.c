/*Подвиг 7 (релакс). Напишите программу, которая читает четыре целых числа из входного потока, записанных в одну строчку через пробел. Объявите функцию с сигнатурой:

int sum_big2(int a, int b, int c, int d);
Эта функция должна складывать два наибольших числа из четырех переданных и возвращать значение суммы. Вызовите функцию sum_big2 в функции main для прочитанных чисел из входного потока. Выведите в консоль полученное значение суммы в виде одного целого числа.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.5.7*/
#include <stdio.h>

int sum(int a, int b){
    return a > b ? a : b;
}
int sum_big2(int a,int b,int c,int d){
    
    return sum(a,d)+sum(c,b);

}


int main(void)
{
    int a,b,c,d;
    int sum = 0;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    sum = sum_big2(a,b,c,d);
    printf("%d ",sum);

    return 0;
}