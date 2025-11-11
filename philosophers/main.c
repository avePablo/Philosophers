/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:59:29 by pabalvar          #+#    #+#             */
/*   Updated: 2025/11/11 15:50:56 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_mutexes(t_general *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->death_lock);
}

void	create_philo_threads(t_general *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_create(&data->philo[i].thread, NULL, ft_routine,
			&data->philo[i]);
		i++;
	}
}

void	join_philo_threads(t_general *data, pthread_t monitor_thread)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
}

int	init_main(int argc, char **argv, t_general *data)
{
	if (parse(argc, argv) == 3)
	{
		one_philo_only(data);
		return (2);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_t	monitor_thread;
	t_general	*data;

	if (parse(argc, argv) != 0 && parse(argc, argv) < 3)
	{
		error_handler(parse(argc, argv));
		return (1);
	}
	data = malloc(sizeof(t_general));
	data->philo = malloc(sizeof(t_philosophers) * ft_atol(argv[1]));
	init_general(data, argv);
	init_philos(data->philo, data);
	if (init_main(argc, argv, data) == 2)
	{
		free(data);
		return (1);
	}
	create_philo_threads(data);
	pthread_create(&monitor_thread, NULL, monitor, data);
	join_philo_threads(data, monitor_thread);
	destroy_mutexes(data);
	free(data->philo);
	free(data);
	return (0);
}
