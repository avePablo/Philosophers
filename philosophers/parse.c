/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:59:34 by pabalvar          #+#    #+#             */
/*   Updated: 2025/11/11 13:04:29 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parse(int argc, char **argv)
{
	long	arg;
	int		i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (1);
	while (i < argc)
	{
		arg = ft_atol(argv[i]);
		if (is_digit_str(argv[i]) == 1)
			return (1);
		if (i == 1 && (arg == 1))
			return (3);
		if (i == 1 && (arg < 1 || arg > PHILO_MAX_COUNT))
			return (1);
		else if (i == 5 && (arg < 0 || arg > INT_MAX))
			return (1);
		else if (i == 5 && arg == 0)
			return (2);
		else if (i != 1 && i != 5 && (arg < 1 || arg > INT_MAX))
			return (1);
		i++;
	}
	return (0);
}

void	init_philos(t_philosophers *philo, t_general *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		philo[i].id = i + 1;
		philo[i].fork_l = i;
		philo[i].fork_r = (i + 1) % data->number_of_philosophers;
		philo[i].last_meal = timestamp_ms();
		philo[i].data = data;
		philo[i].times_eaten = 0;
		i++;
	}
}

void	init_general(t_general *data, char *argv[])
{
	int	i;

	i = 0;
	data->number_of_philosophers = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->dead = 0;
	data->number_of_times_each_philosopher_must_eat = -1;
	if (argv[5])
		data->number_of_times_each_philosopher_must_eat = ft_atol(argv[5]);
	data->start_time = timestamp_ms();
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

int	is_dead(t_general *data)
{
	int	dead_status;

	pthread_mutex_lock(&data->death_lock);
	dead_status = data->dead;
	pthread_mutex_unlock(&data->death_lock);
	return (dead_status);
}

void	one_philo_only(t_general *data)
{
	long long	now;

	now = timestamp_ms();
	pthread_mutex_lock(&data->print);
	printf("%lld ms  Philosopher %d died\n", (now - data->start_time) % 100000,
		data->philo[0].id);
	pthread_mutex_unlock(&data->print);
}
