#include <stdio.h>
 
#define COLS      3
 
void show_ar2D(const short (*ar)[COLS], int rows)
{
         for(int i = 0;i < rows; ++i) {
                   for(int j = 0;j < COLS; ++j)
                            printf("%d ", ar[i][j]);
                   printf("\n");
         }
}
 
int main(void) 
{
         short ar[][COLS] = {{1, 2, 3}, {4, 5, 6}};
         show_ar2D(ar, sizeof(ar) / sizeof(*ar));
         
         return 0;
}