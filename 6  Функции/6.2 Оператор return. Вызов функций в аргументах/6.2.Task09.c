/*Подвиг 9. Известно, что среднее арифметическое от m чисел можно вычислять рекуррентно по формуле:
Qm = (m-1)/m*Qm_1+1/n*x
где Qm_1 - среднее арифметическое от предыдущих m-1 чисел; x - новое m-е значение.
В программе ниже необходимо реализовать подсчет среднего арифметического читаемых целых чисел из входного потока. Для этого объявите функцию со следующей сигнатурой:
double get_qm(double qm_1, int m, int x);
Функция get_qm должна вычислять очередное значение среднего арифметического для m прочитанных чисел и возвращать вычисленное значение Qm. В записанном цикле while с помощью функции get_qm вычислите среднее арифметическое всех прочитанных целых чисел из входного потока. Выведите результат вычисления в консоль в виде вещественного числа с точностью до тысячных.
Тесты: https://github.com/selfedu-rus/c-tests/tree/main/6.2.9*/
#include <stdio.h>

double get_qm(double qm_1, int m, int x){
     return ((m-1)*qm_1+x)/m; 
}

int main(void)
{
    int x;
    int m = 1;
    double qm, qm_1;
    
    while(scanf("%d", &x) == 1) {
        qm = get_qm(qm_1, m, x);
        qm_1 = qm;
        m++;
    }
    printf("%.3f", qm);
    return 0;
}