/*Подвиг 4* (продолжение, на повторение). Скопируйте программу, написанную в предыдущем 3-м подвиге. Необходимо добавить функцию поиска кратчайшего маршрута от одной станции до другой. Функция должна иметь следующую сигнатуру:

void find_path(STATION* from, STATION* to, STATION *path[], int* count_st);
Здесь from - начальная станция; to - конечная станция; path - массив указателей из станций метро кратчайшего маршрута (включая станции from и to); count_st - указатель на целочисленную переменную, хранящую общее число станций в найденном маршруте. Станции в массиве path должны следовать от начальной from до конечной to, без перескоков через станции, последовательно.

Пример использования функции find_path:

STATION* path[max_path_station];
int count_st = 0;

find_path(&st[0], &st[9], path, &count_st);

for(int i = 0;i < count_st;++i)
    printf("[%s] ", path[i]->name);
P. S. В консоль ничего выводить не нужно, только добавить функцию find_path и другие вспомогательные функции для поиска кратчайшего маршрута.*/
#include <stdio.h>
#include <stdarg.h>


enum {name_length=50, total_links=50, max_path_station=100};

typedef struct tag_station {
    char name[name_length];                 // название станции метро
    struct tag_station* links[total_links]; // связи станции метро с другими соседними станциями
    short count_links;                      // общее количество связей
    char fl_reserved;                       // зарезервированная переменная (полезна при реализации алгоритма поиска маршрута)
} STATION;

void set_station_links(STATION* st, int count_links, ...)
{
   va_list arg;                  // указатель на параметр
   va_start(arg, count_links);   // получение адреса первого вариадического параметра 
     for( int i = 0; i < count_links; i++ ) {
         st->links[ i ] = (STATION*)va_arg(arg, void* ); // и переход к следующему параметру  
      }
      va_end(arg);               // завершение процедуры перебора вариадических параметров
    st->count_links = count_links;
}    

/// Рекурсивный обход станций.
void make_wave( STATION* from, STATION* to, int count )
{
    from->fl_reserved = count;
    for( int i = 0; i < from->count_links; i++ ) {  /// Осматриваем все соседние станции
        if( from->links[ i ]->fl_reserved == 0 )    /// здесь еще не были.
            make_wave( from->links[ i ], to, count + 1 );  /// ищем дальше
        if( from->links[ i ]->fl_reserved > count + 1 )      /// а сюда, оказывается, есть путь короче
            make_wave( from->links[ i ], to, count + 1 );  /// снова ищем от этой станции           
    }
}

void find_path(STATION* from, STATION* to, STATION *path[], int* count_st)
{
    make_wave( from, to, 1 );              /// Расставляем расстояния от начальной станции.
    STATION *next = to;                    /// стартовая точка поиска - ищем от конечной.
    size_t idx = to->fl_reserved - 1;      /// индекс для записи в path[].
    path[ idx-- ] = next;                  /// Добавляем в оптимальный путь.
    *count_st = to->fl_reserved;           /// Длина пути до конечной известна. 
    while( next != from ) {
        for( int i = 0; i < next->count_links; i++ ) {                    /// перебираем соседние станции.
            if( next->links[ i ]->fl_reserved = next->fl_reserved - 1 ) { /// нашлась оптимальная станция
                next = next->links[ i ];   /// устанавливаем откуда дальше искать будем.
                path[ idx-- ] = next;      /// Добавляем в оптимальный путь.
                break;
            }
        }
    }
}
int main(void)
{
    STATION st[10] = {
        {"St #1", .count_links=0, .fl_reserved=0},
        {"St #2", .count_links=0, .fl_reserved=0},
        {"St #3", .count_links=0, .fl_reserved=0},
        {"St #4", .count_links=0, .fl_reserved=0},
        {"St #5", .count_links=0, .fl_reserved=0},
        {"St #6", .count_links=0, .fl_reserved=0},
        {"St #7", .count_links=0, .fl_reserved=0},
        {"St #8", .count_links=0, .fl_reserved=0},
        {"St #9", .count_links=0, .fl_reserved=0},
        {"St #10", .count_links=0, .fl_reserved=0},
    };

    // здесь описывайте связи между станциями метро
    set_station_links( st    , 2, st + 1, st + 2 );
    set_station_links( st + 1, 3, st,     st + 3, st + 4 );
    
    set_station_links( st + 2, 2, st + 0, st + 5 );
    set_station_links( st + 3, 2, st + 1, st + 5 );
    
    set_station_links( st + 4, 2, st + 1, st + 7 );    
    set_station_links( st + 5, 4, st + 2, st + 3, st + 6, st + 8 ); 
    
    set_station_links( st + 6, 2, st + 5, st + 8 );
    set_station_links( st + 7, 2, st + 4, st + 8 );
    
    set_station_links( st + 8, 4, st + 5, st + 6, st + 7, st + 9 );
    set_station_links( st + 9, 1, st + 8 );    
    

    __ASSERT_TESTS__ // макроопределение для тестирования (не убирать и должно идти непосредственно перед return 0)
    return 0;
}