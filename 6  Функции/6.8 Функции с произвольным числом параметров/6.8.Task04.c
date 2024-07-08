/*Подвиг 4. Объявите в программе вариадическую функцию с именем v_norm2, в которой должны быть определены следующие параметры (порядок важен):
указатель на строку (массив типа char);
вариадические параметры (тип double).
Функция v_norm2 должна вычислять норму вектора по следующему правилу:
 - если в первом параметре строка "vector2", то вектор имеет две координаты;
 - если в первом параметре строка "vector3", то вектор имеет три координаты;
 - если в первом параметре строка "vector4", то вектор имеет четыре координаты;
 - если в первом параметре иная строка, то норма не вычисляется и возвращается 0.0.
Квадратичная норма вектора вычисляется по формуле:
norm = x^2 + y^2 +...
где x, y, ... - координаты вектора (передаются через вариадические параметры). 
Функция v_norm2 должна возвращать вычисленную норму в виде вещественного числа типа double.
В функции main вызовите функцию v_norm2 для вычисления квадратичной нормы двумерного вектора с координатами 1.0 и 2.0. Выведите результат в консоль в виде вещественного числа с точностью до десятых.*/
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

double v_norm2(const char* vector_type, ...) {
    va_list args;
    va_start(args, vector_type);

    int num_coords = 0;
    if (strcmp(vector_type, "vector2") == 0) {
        num_coords = 2;
    } else if (strcmp(vector_type, "vector3") == 0) {
        num_coords = 3;
    } else if (strcmp(vector_type, "vector4") == 0) {
        num_coords = 4;
    } else {
        va_end(args);
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < num_coords; i++) {
        double coord = va_arg(args, double);
        sum += coord * coord;
    }
    va_end(args);

    return sum;
}

int main(void) {
    double result = v_norm2("vector2", 1.0, 2.0);
    printf("%.1f\n", result);

    return 0;
}
