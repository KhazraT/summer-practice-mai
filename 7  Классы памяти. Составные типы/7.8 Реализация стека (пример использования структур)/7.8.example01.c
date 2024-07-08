#include <stdio.h>

typedef struct tag_obj {
    int data;
    struct tag_obj* next;
} OBJ;

OBJ* push(OBJ* top, int data)
{
    OBJ* ptr = malloc(sizeof(OBJ));
    ptr->data = data;
    ptr->next = top;
    return ptr;
}

OBJ* pop(OBJ* top)
{
    if(top == NULL)
        return top;
    
    printf("Deleted: %d\n", top->data);
 
    OBJ* ptr_next = top->next;
    free(top);
 
    return ptr_next;
}

void show_stack(const OBJ* top)
{
    const OBJ* current = top;
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main(void) 
{
    OBJ* top = NULL;
 
    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
 
    show_stack(top);
 
    while(top)
        top = pop(top);
 
    return 0;
}