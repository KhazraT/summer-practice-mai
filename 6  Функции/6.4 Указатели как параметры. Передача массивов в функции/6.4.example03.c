#include <stdio.h>
 
void show_ar2D(const short (*ar)[3], int rows)
{
         for(int i = 0;i < rows; ++i) {
                   for(int j = 0;j < 3; ++j)
                            printf("%d ", ar[i][j]);
                   printf("\n");
         }
}
 
int main(void) 
{
         short ar[][3] = {{1, 2, 3}, {4, 5, 6}};
         show_ar2D(ar, sizeof(ar) / sizeof(*ar));
         
         return 0;
}