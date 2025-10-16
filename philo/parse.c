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

void asig_struct(char *argv[])
{
t_general *data = malloc(sizeof(t_general));
init_general(data, argv);

t_philosophers *philo = malloc(sizeof(t_philosophers) * data->number_of_philosophers);
init_philos(philo, data->number_of_philosophers);

//                                                      To Do: para que vaya imprimiendo lo que hace cada philo con colores, los colores ya están falta el codigo 

//int i = 0;
// while(i < data->number_of_philosophers)
// {
//     print_threads(data[i].number_of_philosophers); //colorines
//     i++;
// }
print_philos(data, philo, data->number_of_philosophers); //borrar luego, imprime el struct pa ver que esta bien 
}