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
    const char* colors[5] = {RED, GREEN, YELLOW, BLUE, MAGENTA};
    index = id % 5;
    printf("%s colorines%s\n", colors[index], RESET);
    //to do para qe imprima todo lo que debe
}
int is_digit_str (char* str)
{
    int i;
    i = 0;
    if (!(str[i] >= '0' && str[i] <= '9'))
	{
        return 1;
        i++;
    }
	return 0;
}