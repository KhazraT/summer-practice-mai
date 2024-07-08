/*Подвиг 5. Продолжите программу. Выше в тексте программы объявлена переменная price_100 структуры tag_price (она скрыта, но она существует). В функции main необходимо объявить переменную с именем pr той же структуры tag_price и скопировать данные из переменной price_100 в переменную pr. Выведите значения полей переменной pr в консоль в одну строчку через пробел в порядке их описания в структуре tag_price. Все поля, кроме name, должны выводиться десятичными числами.*/
#include <stdio.h>

/*
struct tag_price {
    char name[100];
    unsigned int rubs;
    unsigned short kops;
    unsigned int foreign_key;
};
*/

int main(void)
{
    // здесь продолжайте функцию main
    struct tag_price pr = price_100;
    printf("%s %d %d %d", pr.name, pr.rubs, pr.kops, pr.foreign_key);

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}