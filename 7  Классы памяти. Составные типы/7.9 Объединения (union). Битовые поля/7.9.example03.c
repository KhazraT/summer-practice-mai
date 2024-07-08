#include <stdio.h>

struct date_time {
    unsigned day : 5;
    unsigned month : 4;
    unsigned year : 12;
    unsigned sec : 6;
    unsigned min : 6;
    unsigned hour : 5;
};

int main(void) 
{
    struct date_time dt;
    printf("%d\n", sizeof(dt));
    
    struct date_time dt = {3, 5, 2023, 11, 7, 10};
    printf("%02d/%02d/%d %02d:%02d:%02d\n", dt.day, dt.month, dt.year, dt.hour, dt.min, dt.sec);
    

    return 0;
}