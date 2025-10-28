#include "philosophers.h"

void init_philos(t_philosophers *philo, t_general *data)
{
    int i = 0;
    while (i < data->number_of_philosophers)
    {
        philo[i].id = i + 1;
        philo[i].fork_l = i;
        philo[i].fork_r = (i + 1) % data->number_of_philosophers;
        philo[i].last_meal = timestamp_ms();
        philo[i].data = data;
        i++;
    }
}

void init_general(t_general *data, char *argv[])
{
    data->number_of_philosophers = ft_atoi(argv[1]);
    data->time_to_die = ft_atol(argv[2]);
    data->time_to_eat = ft_atol(argv[3]);
    data->time_to_sleep = ft_atol(argv[4]);
    data->dead = 0;
    data->number_of_times_each_philosopher_must_eat = (argv[5]) ? atoi(argv[5]) : -1;

    pthread_mutex_init(&data->print, NULL);

    int i = 0;
    while (i < data->number_of_philosophers)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
}

void create_philo_threads(t_general *data)
{
    int i = 0;
    while (i < data->number_of_philosophers)
    {
        pthread_create(&data->philo[i].thread, NULL, ft_routine, &data->philo[i]);
        i++;
    }
}

void join_philo_threads(t_general *data, pthread_t monitor_thread)
{
    int i = 0;
    while (i < data->number_of_philosophers)
    {
        pthread_join(data->philo[i].thread, NULL);
        i++;
    }
    pthread_join(monitor_thread, NULL);
}

int main(int argc, char **argv)
{
    int i = 0;
    pthread_t monitor_thread;
    
    i = parse(argc, argv);
    if(i != 0)
    {
        error_handler(i);
        return 1;
    }
    t_general *data = malloc(sizeof(t_general));
    data->philo = malloc(sizeof(t_philosophers) * ft_atoi(argv[1]));
    init_general(data, argv);
    init_philos(data->philo, data);
    print_philos(data);
    create_philo_threads(data);
    pthread_create(&monitor_thread, NULL, monitor, data);
    join_philo_threads(data, monitor_thread);
    free(data->philo);
    free(data);
    return 0;
}