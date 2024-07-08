#include <stdio.h>

int sq_rect(int width, int height)
{
         return width * height;
}

int per_rect(int width, int height)
{
         return 2 * (width + height);
}

void print_hi(void)
{
         puts("Hi!");
}

int (*ptr_func) (int, int);

int main(void) 
{
        printf("sq_rect = %p\n", sq_rect);

        ptr_func = sq_rect;
        int res = ptr_func(2, 3);
        printf("ptr_func(2, 3) = %d\n", res);

        ptr_func = per_rect;
        int res = ptr_func(2, 3);

        ptr_func = print_hi;
        void (*ptr_hi) (void);
        ptr_hi = print_hi;
        ptr_hi();

         return 0;
}