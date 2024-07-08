#include <stdio.h>

enum {name_length=50, b_length=20}; 
struct tag_array {
    int marks[b_length];
};
 
int main(void) 
{
    struct tag_array marks_1 = {2, 2, 2, 3, 2, 2};
    struct tag_array marks_2;
 
    marks_2 = marks_1;
    for(int i = 0;i < sizeof(marks_2.marks) / sizeof(*marks_2.marks); ++i)
        printf("%d ", marks_2.marks[i]);
        
    return 0;
}