#include "philosophers.h"

void take_forks(t_philosophers *p)
{
    if (p->id % 2 == 0)
    {
        pthread_mutex_lock(&p->data->forks[p->fork_r]);
        print_state(p, "has taken the right fork");
        pthread_mutex_lock(&p->data->forks[p->fork_l]);
        print_state(p, "has taken the left fork");
    }
    else
    {
        pthread_mutex_lock(&p->data->forks[p->fork_l]);
        print_state(p, "has taken the left fork");
        pthread_mutex_lock(&p->data->forks[p->fork_r]);
        print_state(p, "has taken the right fork");
    }
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
    smart_sleep(p->data->time_to_eat, p->data);

}

void sleep_philo(t_philosophers *p)
{
    print_state(p, "is sleeping");
   smart_sleep(p->data->time_to_sleep, p->data);

}

void think(t_philosophers *p)
{
    print_state(p, "is thinking");
}
