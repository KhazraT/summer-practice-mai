#include <stdio.h>
 
typedef enum {
    buffer_size = 2048,
    element_size = 12,
    window_size = 400
} SIZE_CONSTS;
 
int main(void) 
{
    SIZE_CONSTS sizes = window_size;
    printf("%d\n", sizes);
    printf("%d\n", buffer_size);
 
    return 0;
}