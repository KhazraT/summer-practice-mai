#include <stdio.h>

int get_per(int width, int height)
{
         return 2 * (width + height);
}

int main(void) 
{
         int w = 2, h = 5;
         
         get_per(w, h);
         int per_1 = get_per(w+1, h-4);
         int per_2 = get_per(w, 3);
         int per_3 = get_per(1, 3);
 
         return 0;
}
