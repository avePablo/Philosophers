#include "philosophers.h"

void one_philo_only(t_general *data)
{
    
            long long now = timestamp_ms();
 
                pthread_mutex_lock(&data->print);
                printf("%lld ms  Philosopher %d died\n",
                       (now - data->start_time) % 100000, data->philo[1].id);
                data->dead = 1;
                pthread_mutex_unlock(&data->print);

}

int parse(int argc, char** argv)
{   
    long arg;
    int i;
    i = 1;
    if (argc < 5 || argc > 6)
        return 1;
    while(i < argc)
    {
        arg = ft_atol(argv[i]);
        if (is_digit_str(argv[i]) == 1)
        return 1;
        if (i == 1 && (arg == 1))
        {
        return 3;
        }
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