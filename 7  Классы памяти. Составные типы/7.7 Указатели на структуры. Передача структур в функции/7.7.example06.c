#include <stdio.h>

typedef struct tag_vector {
    double x;
    double y;
} VECTOR;

VECTOR create_vector(double x, double y)
{
    return (VECTOR) {x, y};
}
 
VECTOR sum_vector(const VECTOR* v1, const VECTOR* v2)
{
    return (VECTOR) {v1->x + v2->x, v1->y + v2->y};
}
 
void isum_vector(VECTOR* v1, const VECTOR* v2)
{
    v1->x += v2->x;
    v1->y += v2->y;
}
 
int main(void) 
{
    VECTOR bias = create_vector(2.56, -7.88);
    VECTOR one = create_vector(1.0, 1.0);
    VECTOR result = sum_vector(&bias, &one);
    isum_vector(&bias, &(VECTOR) {0.5, -0.5});
 
    return 0;
}