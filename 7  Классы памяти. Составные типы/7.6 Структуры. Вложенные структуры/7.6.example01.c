#include <stdio.h>

struct tag_point {
    int x;
    int y;
    int z;
};

int main(void) 
{
    struct tag_point pt;

    pt.x = 1;
    pt.y = 2;
    pt.z = 3;

    size_t sz_pt = sizeof(pt);
    size_t sz_st = sizeof(struct tag_point);
    
    printf("sz_pt = %d, sz_st = %d\n", sz_pt, sz_st);
    printf("x = %d, y = %d, z = %d\n", pt.x, pt.y, pt.z);

    return 0;
}