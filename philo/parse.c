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
    if (!data)
        return;

    init_general(data, argv);

    init_philos(data->philo, data->number_of_philosophers);

    mutex_create(data);
    thread_create(data);

    for (int i = 0; i < data->number_of_philosophers; i++)
        pthread_join(data->philo[i].thread, NULL);

    free(data);
}



//                                                      To Do: para que vaya imprimiendo lo que hace cada philo con colores, los colores ya están falta el codigo 

//int i = 0;
// while(i < data->number_of_philosophers)
// {
//     print_threads(data[i].number_of_philosophers); //colorines
//     i++;
// }
// print_philos(data, philo, data->number_of_philosophers); //borrar luego, imprime el struct pa ver que esta bien 
