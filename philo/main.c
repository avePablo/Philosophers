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
        arg = ft_atoi(argv[i]);
        if (i == 1 && (arg < 1 || arg > PHILO_MAX_COUNT))
        return 1;
        else if (i == 5 && (arg < 0 || arg > INT_MAX))
        return 1;
        else if (i != 1 && i != 5 && (arg < 1 || arg > INT_MAX))
        return 1;
        i++;
    }
    return 0;
}

void init_philos()
{
t_philosophers *philo;
}

void init_general()
{
t_general *data;

data->number_of_philosophers = 0;
data->number_of_times_each_philosopher_must_eat = 0;
}

void asig_struct(argv)
{
int i;
i = 0;
while (argv[i])
{   
    if (argv[i] = 1)
    data->number_of_philosophers=ft_atoi(argv[i]);
    else if (argv[i] = 5)
    data->number_of_times_each_philosopher_must_eat=ft_atoi(argv[i]);
    i++;
}
}

int main(int argc, char** argv)
{
    if(parse(argc, argv) == 1)
    {
        error_handler();
        return 1;
    }
    init_struct();
    asig_struct(argv);
    return 0;
}