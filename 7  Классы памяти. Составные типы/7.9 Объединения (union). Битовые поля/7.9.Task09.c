/*Подвиг 9. Продолжите программу. Объявите в программе битовое поле с типом PERSON_DATA и следующими переменными (порядок важен):

old; 7 бит; возраст
salary; 20 бит; зарплата
height; 8 бит; рост
weight; 7 бит; вес
В функции main объявите переменную с именем pd и типом PERSON_DATA. Занесите в нее значения:

возраст 45, зарплата 876043, рост 186, вес 83

Выведите в консоль размер, который занимает переменная pd в памяти компьютера.*/
#include <stdio.h>

typedef struct
{
    unsigned old: 7;
    unsigned salary: 20;
    unsigned height: 8;
    unsigned weight: 7;
} PERSON_DATA;

int main(void)
{
    PERSON_DATA pd = {45, 876043, 186, 83};
    printf("%zu\n", sizeof(pd));

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}