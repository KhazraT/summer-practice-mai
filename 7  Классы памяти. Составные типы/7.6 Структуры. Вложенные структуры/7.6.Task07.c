/*Подвиг 7. Продолжите программу. В функции main объявите две переменные tm1 и tm2 структуры tag_time. Значения их полей (шесть целых неотрицательных чисел, записанных в одну строчку через пробел) прочитайте из входного потока. Объявите еще одну переменную tm_sum структуры tag_time, поля которой должны содержать сумму времен переменных tm1 и tm2. Время нужно складывать так, чтобы минуты и секунды не выходили из пределов [0; 59]. Выведите в консоль полученное время tm_sum в формате:

hh:mm:ss

Например:

12:08:43

(Обратите внимание на наличие незначащего нуля перед числами меньше 10).*/
#include <stdio.h>

struct tag_time {
    unsigned char hours;
    unsigned char minutes;
    unsigned char seconds;
};

struct tag_time sum_time(struct tag_time tm1, struct tag_time tm2) {
    struct tag_time sum;

    sum.seconds = (tm1.seconds + tm2.seconds) % 60;
    int add_min = (tm1.seconds + tm2.seconds) / 60;
    sum.minutes = (tm1.minutes + tm2.minutes + add_min) % 60;
    int add_hrs = (tm1.minutes + tm2.minutes + add_min) / 60;
    sum.hours = tm1.hours + tm2.hours + add_hrs;

    return sum;
}

int main(void) {
    struct tag_time tm1, tm2;
    scanf("%hhu %hhu %hhu %hhu %hhu %hhu", &tm1.hours, &tm1.minutes, &tm1.seconds, 
          &tm2.hours, &tm2.minutes, &tm2.seconds);

    struct tag_time tm_sum = sum_time(tm1, tm2);
    printf("%02d:%02d:%02d\n", tm_sum.hours, tm_sum.minutes, tm_sum.seconds);

    __ASSERT_TESTS__
        
    return 0;
}