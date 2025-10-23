#include "philosophers.h"

int thread_create(t_general *general)
{
    t_philosophers *philo;
    int i;
    i = 0;
    philo = general->philo;
   
    while (i < general->number_of_philosophers)
    {
        pthread_create(&philo[i].thread, NULL, (void *)ft_routine(general), NULL);    
        i++;   
    }
    return 0;
    }   

int mutex_create(t_general *general)
{
    pthread_mutex_init(&(general->a), NULL);
    return 0;
}

int main(int argc, char** argv)
{
    int i = parse(argc, argv);
    if(i != 0)
    {
        error_handler(i);
        return 1;
    }
    asig_struct(argv);
    
    return 0;
}