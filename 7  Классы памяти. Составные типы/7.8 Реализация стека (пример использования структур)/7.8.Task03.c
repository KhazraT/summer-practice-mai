/*Подвиг 3 (на повторение, без стека). Необходимо написать программу, которая бы описывала следующую схему станций метро:
![ris_8.png](ris_8.png "ris_8.png")
Для этого необходимо объявить следующую структуру:

enum {name_length=50, total_links=50, max_path_station=100};

typedef struct tag_station {
    char name[name_length];                 // название станции метро
    struct tag_station* links[total_links]; // связи станции метро с другими соседними станциями
    short count_links;                      // общее количество связей
    char fl_reserved;                       // зарезервированная переменная (полезна при реализации алгоритма поиска маршрута)
} STATION;
После этого объявите вариадическую функцию set_station_links со следующей сигнатурой:

void set_station_links(STATION* st, int count_links, ...)
Здесь st - станция метро, для которой формируются связи с другими соседними станциями; count_links - общее число таких связей; вариадические параметры должны представлять собой указатели типа STATION* в количестве count_links, которые заносятся в массив links объекта st. То есть, функция set_station_links связывает объект st с другими, указанными в вариадических параметрах объектами, записывая их адреса в массив links. Также не забудьте задать значение поля count_links в объекте (структуре) st.

Продолжите функцию main, в которой с помощью функции set_station_links сформируйте связи между станциями метро в соответствии с приведенным рисунком.

P. S. В консоль ничего выводить не нужно.*/
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