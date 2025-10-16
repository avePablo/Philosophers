#include "philosophers.h"

void init_philos(t_philosophers *philo, int number_of_philosophers)
{
     int i;
     i = 0;

     while (i < number_of_philosophers)
     {   
          philo[i].id = i + 1;
          philo[i].fork_r = i + 1;
          i++;
     }
}

void init_general(t_general *data, char *argv[])
{
     data->number_of_philosophers = ft_atoi(argv[1]);
     data->time_to_die = ft_atol(argv[2]);
     data->time_to_eat = ft_atol(argv[3]);
     data->time_to_sleep = ft_atol(argv[4]);
     if (argv[5])
     data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
}