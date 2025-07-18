#include "philosophers.h"

void error_handler()
{
    ft_printf("invalid/wrong number of arguments");
}

void error_handler_free()
{
    ft_printf("");
    //free(); to do
}

void print_threads(int id)
{
    int index;
    const char* colors[6] = {RESET, RED, GREEN, YELLOW, BLUE, MAGENTA};
    index = id % 6;
    printf("%s colorines%s\n", colors[index], RESET);
    //to do para qe imprima todo lo que debe
}