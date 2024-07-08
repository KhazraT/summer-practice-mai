/*Подвиг 7. Объявите в программе структуру с полями x, y типа int и определите для нее тип POINT. Объявите функцию с именем rect_square и двумя параметрами в виде указателей, через которые передаются структуры типа POINT. Функция rect_square должна вычислять площадь прямоугольника, заданного двумя точками (типа POINT): верхнего левого угла и нижнего правого:
![ris_7.png](ris_7.png "ris_7.png")
Вычисленное значение возвращается функцией rect_square в виде целого числа.

В функции main прочитайте из входного потока четыре целых числа, записанных в одну строчку через пробел, и сохраните их в двух переменных типа POINT в порядке x0, y0, x1, y1. Вызовите функцию rect_square для сформированных точек (структур POINT) и выведите в консоль возвращенное функцией значение в виде одного целого числа.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/7.7.7*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} POINT;

int rect_square (const POINT *ptr_1, const POINT *ptr_2)
{
    return abs(ptr_1->x - ptr_2->x) * abs(ptr_1->y - ptr_2->y);
}

int main(void)
{
    POINT p1, p2;
    scanf("%d%d%d%d", &p1.x, &p1.y, &p2.x, &p2.y);

    int sq = rect_square(&p1, &p2);
    printf("%d\n", sq);
    return 0;
}
