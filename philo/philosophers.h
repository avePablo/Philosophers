#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
#include "../Libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

#define PHILO_MAX_COUNT 200

typedef struct s_philosophers
{
    int id;
    int fork_1;
    int fork_r;
    int status;
}					t_philosophers;

typedef struct s_general
{
    float time_to_die;
    float time_to_eat;
    float time_to_sleep;
	int number_of_philosophers;
    int number_of_times_each_philosopher_must_eat;
}					t_general;

int main(int argc, char** argv);

int parse(int argc, char** argv);

void error_handler();

void error_handler_free();

void asig_struct(char *argv[]);

void init_general(t_general *data, char *argv[]);

void init_philos(t_philosophers *philo, int number_of_philosophers);

void print_philos(t_general *data, t_philosophers *philo, int number_of_philosophers);

#endif