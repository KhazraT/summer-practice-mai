/*Подвиг 8. Объявите в программе структуру с полями x, y типа int и определите для нее тип POINT. Объявите функцию с именем get_means и двумя параметрами (порядок важен):

 - одномерным массивом структур POINT;
 - длиной (числом элементов) этого массива (тип size_t).
Функция get_means должна вычислять два средних арифметических числа: отдельно для первой координаты x и отдельно для второй координаты y. Вычисленные вещественные значения сохранить в структуре типа DATA (объявить до функции), которая содержит два поля: mean_x и mean_y типа double. Функция get_means должна возвращать сформированную структуру DATA.

В функции main объявите массив points структур POINT длиной 20 элементов. Прочитайте из входного потока целые числа x0, y0, x1, y1, ..., записанные в одну строчку через пробел. Максимальное число пар чисел не превышает 20, но может быть и меньше. Вызовите функцию get_means для вычисления средних только для актуальных элементов массива points (тех, в которых хранятся данные из входного потока, а не все 20). Возвращенные значения вывести в консоль в одну строчку через пробел с точностью до сотых.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/7.7.8*/
#include <stdio.h>

typedef struct {
    int x;
    int y;
} POINT;

typedef struct {
    double mean_x;
    double mean_y;
} DATA;

DATA get_means(POINT* ar, size_t len){
    double sum_x = 0, sum_y = 0;

    for (int i = 0; i < len; i++){
        sum_x += ar[i].x;
        sum_y += ar[i].y;
    }
    
    return (DATA) {sum_x / len, sum_y / len};
}

int main(void)
{
    POINT points[20];
    int cnt = 0;
    int max_size = sizeof(points) / sizeof(*points);
    
    while(scanf("%d %d", &points[cnt].x, &points[cnt].y) == 2 && cnt < max_size){
        cnt++;
    }
    
    DATA res = get_means(points, cnt);
    printf("%.2f %.2f", res.mean_x, res.mean_y);

    return 0;
}