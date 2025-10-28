#include "philosophers.h"

void error_handler(int err)
{   
    if (err == 1)
    ft_printf("invalid/wrong number of arguments");
    else if (err == 2)
     printf("un filosofo no puede comer 0 veces");
}

void error_handler_free()
{
    ft_printf("");
    //free(); to do
}

void print_threads(int id)
{
    int index;
    const char* colors[5] = {RED, GREEN, YELLOW, BLUE, MAGENTA};
    index = id % 5;
    printf("%s colorines%s\n", colors[index], RESET);
    //to do para qe imprima todo lo que debe
}
int is_digit_str(char *str)
{
    int i = 0;
    if (!str || !str[0])
        return 1;
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 1;
        i++;
    }
    return 0;
}
