#include <stdio.h>
#include <stdlib.h>
 
int main(void) 
{
    char* ar = malloc(10);   // выделение 10 байт из кучи
    int* ptr_int = malloc(sizeof(int)); // выделение памяти под тип int
    int* ptr_short = malloc(7 * sizeof(short)); // выделение памяти под 7 элементов типа short
 
    free(ar);
    free(ptr_int);
    free(ptr_short);
    
    return 0;
}