#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
#include "../Libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <pthread.h>
#include <stdio.h>

#define PHILO_MAX_COUNT 200
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"


typedef struct s_philosophers
{
    int id;
    int fork_1;
    int fork_r;
    int status;
    pthread_t   thread;
}					t_philosophers;

typedef struct s_general
{
    long long time_to_die;
    long long time_to_eat;
    long long time_to_sleep;
	int number_of_philosophers;
    int number_of_times_each_philosopher_must_eat;
    t_philosophers philo[200];
    pthread_mutex_t a;
}					t_general;

int main(int argc, char** argv);

int mutex_create(t_general *general);

int parse(int argc, char** argv);

void error_handler(int err);

void error_handler_free();

void asig_struct(char *argv[]);

void init_general(t_general *data, char *argv[]);

void init_philos(t_philosophers *philo, int number_of_philosophers);

void print_philos(t_general *data, t_philosophers *philo, int number_of_philosophers);

void print_threads(int id);

int is_digit_str (char* str);

void *ft_routine (void *general);

int thread_create(t_general *general);

#endif