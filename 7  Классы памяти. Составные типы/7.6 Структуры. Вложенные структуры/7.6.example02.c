#include <stdio.h>

struct tag_point {
    int x;
    int y;
    int z;
};

int main(void) 
{
    // struct tag_point pt = {10, 20, 30};
    // struct tag_point pt = {10};
    // struct tag_point pt = {};
    struct tag_point pt = {.y = -1, .x = 2};

    return 0;
}