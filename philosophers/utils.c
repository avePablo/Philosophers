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

int	all_ate(t_general *data)
{
	int	ate;
	int	i;
	int	j;

	ate = 0;
	i = 0;
	j = 0;
	if (data->number_of_times_each_philosopher_must_eat == -1)
		return (ate);
	pthread_mutex_lock(&data->meal_lock);
	while (i < data->number_of_philosophers)
	{
		if (data->philo[i].times_eaten
			>= data->number_of_times_each_philosopher_must_eat)
			j++;
		i++;
	}
	pthread_mutex_unlock(&data->meal_lock);
	if (j == data->number_of_philosophers)
		ate++;
	return (ate);
}

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
	pthread_mutex_lock(&philo->data->death_lock);
	pthread_mutex_lock(&philo->data->print);
	if (!philo->data->dead)
	{
		now = timestamp_ms() - philo->data->start_time;
		printf("%lld %d %s\n", now, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_unlock(&philo->data->death_lock);
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
	while (!is_dead(data))
	{
		if (timestamp_ms() - start >= duration_ms)
			break ;
		usleep(200);
	}
}
