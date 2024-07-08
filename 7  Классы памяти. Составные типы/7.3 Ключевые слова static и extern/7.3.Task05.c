/*Подвиг 5. Допишите программу без использования глобальных переменных, в которой объявляется функция со следующей сигнатурой:

int range(int start, int stop, int step);
При первом запуске она должна настраивать счетчик на формирование последовательности целых чисел от start до stop (включительно) с шагом step. Также первый запуск возвращает первое значение последовательности. При повторных вызовах функции range параметры start, stop, step не должны играть никакого значения. Сама же функция range при каждом новом вызове должна возвращать очередные числа последовательности. Например, при start=5, stop 11, step=2, имеем:

5, 7, 9, 11, 5, 7, 9, 11, 5, 7, 9, 11, 5, 7, 9, 11, 5, 7, 9, 11, ...

То есть, при достижении граничного значения stop, происходит возврат на начальное значение start.

Тесты: https://github.com/selfedu-rus/c-tests/tree/main/7.3.5*/
#include <stdio.h>

int range(int start, int stop, int step) {
    static int flag;
    static int start0, stop0, step0;
    static int current;

    if (!flag) {
        flag = 1;
        start0 = start;
        stop0 = stop;
        step0 = step;
        current = start;

        return current;
    }

    current = current + step0 > stop0 ? start0 : current + step0;
    return current;
}

int main(void) {
    int start, stop, step;
    scanf("%d %d %d", &start, &stop, &step);

    for (int i = 0; i < 20; ++i)
        printf("%d ", range(start, stop, step));

    return 0;
}