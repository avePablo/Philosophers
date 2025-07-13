#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
#include "../Libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define PHILO_MAX_COUNT 200

typedef struct s_philophers
{
    int id;
    float time_to_die;
    float time_to_eat;
    float time_to_sleep;
}					t_philophers;

typedef struct s_general
{
	int number_of_philosophers;
    int number_of_times_each_philosopher_must_eat;
}					t_general;

int main(int argc, char** argv);

int parse(int argc, char** argv);

void error_handler();




#endif