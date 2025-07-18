#include "philosophers.h"

void print_philos(t_general *data, t_philosophers *philo, int number_of_philosophers)
{
    int i = 0;

    while (i < number_of_philosophers)
    {
        ft_printf("Philosopher [%d] has id: %d\n", i, philo[i].id);
        ft_printf("tenedor derecha[%d] es %d\n", philo[i].id, philo[i].fork_r);
        i++;
    }
printf("die %lld\n",data->time_to_die);
printf("eat %lld\n",data->time_to_eat);
printf("sleep %lld\n",data->time_to_sleep);
ft_printf("cuantas veces %d\n",data->number_of_times_each_philosopher_must_eat);
}
