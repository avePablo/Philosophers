#include "philosophers.h"

void error_handler(int err)
{   
    if (err == 1)
    ft_printf("invalid/wrong number of arguments");
    else if (err == 2)
     printf("un filosofo no puede comer 0 veces");
}

void print_philos(t_general *data)
{
    int i = 0;
    while (i < data->number_of_philosophers)
    {
        printf("Philosopher [%d]: L=%d, R=%d\n",
               data->philo[i].id,
               data->philo[i].fork_l,
               data->philo[i].fork_r);
        i++;
    }
    printf("die=%lld, eat=%lld, sleep=%lld, times=%d\n",
           data->time_to_die, data->time_to_eat, data->time_to_sleep,
           data->number_of_times_each_philosopher_must_eat);
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

long long timestamp_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

void print_state(t_philosophers *philo, const char *msg)
{
    pthread_mutex_lock(&philo->data->print);
    if (!philo->data->dead)
        printf("%lld ms  Philosopher %d %s\n",
               timestamp_ms() % 100000, philo->id, msg);
    pthread_mutex_unlock(&philo->data->print);
}
