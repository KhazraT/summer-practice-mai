#include <stdio.h>

struct tag_vector {
    double x;
    double y;
};

// struct tag_vector create_vector(double x, double y)
// {
//     struct tag_vector v = {x, y};
//     return v;
// }

struct tag_vector create_vector(double x, double y)
{
    return (struct tag_vector) {x, y};
}

// struct tag_vector sum_vector(const struct tag_vector v1, const struct tag_vector v2)
// {
//     struct tag_vector res = {v1.x + v2.x, v1.y + v2.y};
//     return res;
// }

// struct tag_vector sum_vector(const struct tag_vector* v1, const struct tag_vector* v2)
// {
//     struct tag_vector res = {v1->x + v2->x, v1->y + v2->y};
//     return res;
// }

struct tag_vector sum_vector(const struct tag_vector* v1, const struct tag_vector* v2)
{
    return (struct tag_vector) {v1->x + v2->x, v1->y + v2->y};
}

void isum_vector(struct tag_vector* v1, const struct tag_vector* v2)
{
    v1->x += v2->x;
    v1->y += v2->y;
}

int main(void) 
{
    struct tag_vector bias = create_vector(2.56, -7.88);
    struct tag_vector one = create_vector(1.0, 1.0);
    struct tag_vector result = sum_vector(&bias, &one);
    isum_vector(&bias, &(struct tag_vector) {0.5, -0.5});


    printf("result.x = %.2f, result.y = %.2f\n", result.x, result.y);
    printf("bias.x = %.2f, bias.y = %.2f\n", bias.x, bias.y);
 
    return 0;
}
