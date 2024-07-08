#include <stdio.h>
 
int sum_ar(const short* arr, int length)
{
         int res = 0;
         for(int i = 0; i < length; ++i)
                   res += arr[i];
 
         return res;
}
 
int main(void) 
{
         short ar[] = {1, 2, 3, 4, 5};
         int res = sum_ar(ar, sizeof(ar) / sizeof(*ar));
         
         printf("res = %d\n", res);
 
         return 0;
}