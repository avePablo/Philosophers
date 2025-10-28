#include "philosophers.h"

void *monitor(void *arg)
{
    t_general *data = (t_general *)arg;

    while (!data->dead)
    {
        int i = 0;
        while (i < data->number_of_philosophers)
        {
            long long now = timestamp_ms();
            if (now - data->philo[i].last_meal > data->time_to_die)
            {
                pthread_mutex_lock(&data->print);
                printf("%lld ms  Philosopher %d died\n",
                       now % 100000, data->philo[i].id);
                data->dead = 1;
                pthread_mutex_unlock(&data->print);
                return NULL;
            }
            i++;
        }
        usleep(1000);
    }
    return NULL;
}

void *ft_routine(void *arg)
{
    t_philosophers *p = (t_philosophers *)arg;

    if (p->id % 2 == 0)
        usleep(50); // ligera desincronización

    while (!p->data->dead)
    {
        take_forks(p);
        eat(p);
        release_forks(p);
        sleep_philo(p);
        think(p);
    }
    return NULL;
}