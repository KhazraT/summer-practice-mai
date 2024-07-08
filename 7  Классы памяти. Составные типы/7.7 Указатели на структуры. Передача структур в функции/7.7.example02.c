#include <stdio.h>

struct tag_vector {
    double x;
    double y;
};

int main(void) 
{
    struct tag_vector* ptr_v = malloc(sizeof(struct tag_vector));
    ptr_v->x = -1.0;
    ptr_v->y = 2.0;
    printf("x = %.2f, y = %.2f\n", ptr_v->x, ptr_v->y);

    free(ptr_v);
    return 0;
}