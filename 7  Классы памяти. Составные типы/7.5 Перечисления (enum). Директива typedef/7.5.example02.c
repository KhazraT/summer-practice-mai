#include <stdio.h>

enum keys {vk_enter=27, vk_space, vk_del=30};
enum colors {red, green, blue} wnd_colors;
enum {
    go = 0x1f00, 
    stop = 0x0001, 
    forward = go,
    run = 0x00a2,
    back = run -1
} actions, commands;

int main(void) 
{
    enum keys k_var;
 
    switch(k_var) {
    case vk_enter:
        puts("vk_enter");
        break;
    case vk_space:
        puts("vk_space");
        break;
    case vk_del:
        puts("vk_del");
        break;
    }
 
    return 0;
}