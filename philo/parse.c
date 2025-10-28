#include "philosophers.h"

int parse(int argc, char** argv)
{   
    long arg;
    int i;
    i = 1;
    if (argc < 5 || argc > 6)
        return 1;
    while(i < argc)
    {
        arg = ft_atol(argv[i]);
        if (is_digit_str(argv[i]) == 1)
        return 1;
        if (i == 1 && (arg < 1 || arg > PHILO_MAX_COUNT))
        return 1;
        else if (i == 5 && (arg < 0 || arg > INT_MAX))
        return 1;
        else if (i == 5 && arg == 0)
        {
        return 2;
        }
        else if (i != 1 && i != 5 && (arg < 1 || arg > INT_MAX))
        return 1;
        i++;
    }
    return 0;
}