/*Подвиг 5. Напишите программу, в которой объявляется перечисление с идентификатором calc_types и константами:

_perimetr=1, _square=2

Объявите функцию с именем calc_rect, которая имеет следующие параметры (порядок важен):

ширина прямоугольника width (тип double);
высота прямоугольника height (тип double);
тип вычислений type (тип calc_types).
Функция должна вычислять либо площадь прямоугольника (если types равен _square), либо его периметр (если types равен _perimetr) и возвращать вычисленное значение (тип double). 

В функции main прочитайте из входного потока одно целое число (для type) и два вещественных числа (width и height), записанных в одну строчку через пробел. Вызовите функцию calc_types с передачей ей прочитанных значений в качестве аргументов. Выведите в консоль вычисленное значение с точностью до десятых.*/
#include <stdio.h>

enum calc_types {_perimetr = 1, _square = 2};

double calc_rect(double w, double h, int types)
{
    switch(types) {
    case _perimetr:
        return (w + h) * 2;
        break;
    case _square:
        return w * h;
        break;
    }

}

int main()
{    
    int type;
    double w, h;
    scanf("%d", &type); 
    scanf("%lf %lf", &w, &h);
    printf("%.1lf", calc_rect(w, h, type));

    return 0;
}