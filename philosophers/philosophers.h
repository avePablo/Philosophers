/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:59:38 by pabalvar          #+#    #+#             */
/*   Updated: 2025/11/07 17:47:02 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <limits.h>
# include <pthread.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX_COUNT 200
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"

typedef struct s_general		t_general;
typedef struct s_philosophers	t_philosophers;

struct							s_philosophers
{
	int							id;
	int							fork_l;
	int							fork_r;
	int							times_eaten;
	long long					last_meal;
	pthread_t					thread;
	t_general					*data;
};

struct							s_general
{
	int							number_of_philosophers;
	long long					time_to_die;
	long long					time_to_eat;
	long long					time_to_sleep;
	int							number_of_times_each_philosopher_must_eat;
	int							dead;
	pthread_mutex_t				forks[200];
	pthread_mutex_t				print;
	pthread_mutex_t				meal_lock;
	t_philosophers				*philo;
	long long					start_time;
};

long							ft_atol(char *str);

void							take_forks(t_philosophers *p);

void							release_forks(t_philosophers *p);

void							eat(t_philosophers *p);

void							sleep_philo(t_philosophers *p);

void							think(t_philosophers *p);

void							init_philos(t_philosophers *philo,
									t_general *data);

void							init_general(t_general *data, char *argv[]);

void							create_philo_threads(t_general *data);

void							join_philo_threads(t_general *data,
									pthread_t monitor_thread);

int								main(int argc, char **argv);

int								parse(int argc, char **argv);

void							*monitor(void *arg);

void							*ft_routine(void *arg);

void							error_handler(int err);

void							print_philos(t_general *data);

int								is_digit_str(char *str);

long long						timestamp_ms(void);

void							print_state(t_philosophers *philo,
									const char *msg);

long long						getime_now(void);

void							smart_sleep(long long duration_ms,
									t_general *data);

void							one_philo_only(t_general *data);

int								all_ate(t_general *data);

void							ate_status(t_general *data);

void							philo_dead(t_general *data, long long now,
									int i);

void							lunch_clean_philos(t_general *data,
									pthread_t monitor_thread);

int								init_main(int argc, char **argv,
									t_general *data);

void							destroy_mutexes(t_general *data);

#endif