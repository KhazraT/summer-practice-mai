#include <stdio.h>

struct tag_vector {
    double x;
    double y;
};

struct tag_vector create_vector(double x, double y)
{
    struct tag_vector v = {x, y};
    return v;
}

int main(void) 
{
    struct tag_vector bias = create_vector(2.56, -7.88);
    printf("bias.x = %.2f, bias.y = %.2f\n", bias.x, bias.y);
 
    return 0;
}