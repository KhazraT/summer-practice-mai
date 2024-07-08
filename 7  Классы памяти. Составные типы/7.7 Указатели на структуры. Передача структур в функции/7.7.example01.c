#include <stdio.h>

struct tag_vector {
    double x;
    double y;
};

int main(void) 
{
    struct tag_vector v = {1.0, 2.0};
    struct tag_vector *ptr_v;
    
    ptr_v = &v;
    (*ptr_v).x = 10.0;      // запись нового значения
    double y = (*ptr_v).y;  // считывание значения

    ptr_v->x = 10.0;      // запись нового значения
    double y = ptr_v->y;  // считывание значения

    return 0;
}