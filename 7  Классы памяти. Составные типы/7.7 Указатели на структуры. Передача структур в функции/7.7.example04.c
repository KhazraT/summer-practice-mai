#include <stdio.h>

struct tag_vector {
    double x;
    double y;
};

struct tag_vector* create_vector(double x, double y)
{
    struct tag_vector* v = malloc(sizeof(struct tag_vector));
    v->x = x;
    v->y = y;
    
    return v;
}

int main(void) 
{
    struct tag_vector* bias = create_vector(2.56, -7.88);
    printf("bias.x = %.2f, bias.y = %.2f\n", bias->x, bias->y);
 
    free(bias);
    return 0;
}

/*утечка памяти:
int main(void) 
{
    struct tag_vector* bias = create_vector(2.56, -7.88);
    bias = create_vector(3.0, -7.0);
 
    printf("bias.x = %.2f, bias.y = %.2f\n", bias->x, bias->y);
 
    free(bias);
    return 0;
}
*/