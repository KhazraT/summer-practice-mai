#include <stdio.h>
#include <stdarg.h>
 
int sum(int count, ...)
{
            int s = 0;
            va_list arg;            // указатель на параметр
            va_start(arg, count);   // получение адреса первого вариадического параметра 
 
            for(int i=0; i < count; ++i) {
                        s += va_arg(arg, int);  // получение значение вариадического параметра
                                                // и переход к следующему параметру
            }
 
            va_end(arg);               // завершение процедуры перебора вариадических параметров
 
            return s;
}
 
 
int main(void) 
{
            int res = sum(5, 1, 2, 3, 4, 5);
            printf("res = %d\n", res);
 
            return 0;
}