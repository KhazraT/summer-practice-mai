#include <stdio.h>

typedef struct {
    union tag_var var;
    TYPE_VAR type;
} VAR;

typedef enum {
    union_var_none, union_var_ch, union_var_i, union_var_d
} TYPE_VAR;

union tag_var {
    char var_ch;
    int var_i;
    double var_d;
};

void show_var(VAR v)
{
    switch(v.type) {
    case union_var_ch:
        printf("var_ch = %c\n", v.var.var_ch);
        break;
    case union_var_i:
        printf("var_i = %d\n", v.var.var_i);
        break;
    case union_var_d:
        printf("var_d = %.2f\n", v.var.var_d);
        break;
    case union_var_none:
        puts("Undefined type var");
        break;
    }
}

int main(void) 
{
    VAR variable;
 
    variable.var.var_ch = 'C';
    variable.var.var_i = 45;
    variable.type = union_var_i;
 
    show_var(variable);
 
    return 0;
}