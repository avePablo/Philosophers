/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:59:45 by pabalvar          #+#    #+#             */
/*   Updated: 2025/11/05 20:59:45 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error_handler(int err)
{
	if (err == 1)
		printf("invalid/wrong number of arguments");
	else if (err == 2)
		printf("un filosofo no puede comer 0 veces");
}

// void	print_philos(t_general *data)
// {
// 	int		i;

// 	i = 0;
// 	while (i < data->number_of_philosophers)
// 	{
// 		printf("Philosopher [%d]: L=%d, R=%d\n", data->philo[i].id,
// 			data->philo[i].fork_l, data->philo[i].fork_r);
// 		i++;
// 	}
// 	printf("die=%lld, eat=%lld, sleep=%lld, times=%d\n", data->time_to_die,
// 		data->time_to_eat, data->time_to_sleep,
// 		data->number_of_times_each_philosopher_must_eat);
// }

long long	timestamp_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_state(t_philosophers *philo, const char *msg)
{
	long long	now;

	now = 0;
	pthread_mutex_lock(&philo->data->print);
	if (!philo->data->dead)
	{
		now = timestamp_ms() - philo->data->start_time;
		printf("%lld %d %s\n", now, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->data->print);
}

long long	getime_now(void)
{
	long long		start;
	long long		new_start;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	start = timestamp_ms();
	new_start = tv.tv_sec * 1000;
	return (new_start - start);
}

void	smart_sleep(long long duration_ms, t_general *data)
{
	long long	start;

	start = timestamp_ms();
	while (!data->dead)
	{
		if (timestamp_ms() - start >= duration_ms)
			break ;
		usleep(100);
	}
}
