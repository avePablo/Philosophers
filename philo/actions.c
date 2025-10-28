#include "philosophers.h"

void take_forks(t_philosophers *p)
{
    pthread_mutex_lock(&p->data->forks[p->fork_l]);
    print_state(p, "has taken the left fork");
    pthread_mutex_lock(&p->data->forks[p->fork_r]);
    print_state(p, "has taken the right fork");
}

void release_forks(t_philosophers *p)
{
    pthread_mutex_unlock(&p->data->forks[p->fork_l]);
    pthread_mutex_unlock(&p->data->forks[p->fork_r]);
}

void eat(t_philosophers *p)
{
    print_state(p, "is eating");
    p->last_meal = timestamp_ms();
    usleep(p->data->time_to_eat * 1000);
}

void sleep_philo(t_philosophers *p)
{
    print_state(p, "is sleeping");
    usleep(p->data->time_to_sleep * 1000);
}

void think(t_philosophers *p)
{
    print_state(p, "is thinking");
}
