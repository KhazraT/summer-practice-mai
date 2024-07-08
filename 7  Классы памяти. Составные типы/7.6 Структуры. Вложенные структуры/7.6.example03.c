#include <stdio.h>

enum {name_length=50, b_length=20};
 
struct tag_fio {
    char name[name_length]; /* имя */
    char last[name_length]; /* фамилия */
};

struct tag_person {
    struct tag_fio fio;     /* ФИО */
    char sex;               /* пол: м или ж */
    unsigned short old;     /* возраст */
    char b_date[b_length];   /* дата рождения */
};

int main(void) 
{
    struct tag_person person = {
        {"Sergey", "Balakirev"},
        'M',
        98,
        "32.07.1925"
    };
    
    printf("sex: %c, b_date: %s\n", person.sex, person.b_date);

    person.old = 17;
    strcpy(person.b_date, "31.07.2006");

    strcpy(person.fio.name, "Sergiy");
    printf("name: %s, last: %s\n", person.fio.name, person.fio.last);

    struct tag_person p;
    p = person;
    printf("old: %d, b_date: %s\n", p.old, p.b_date);

    return 0;
}