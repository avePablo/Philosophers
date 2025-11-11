/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:59:41 by pabalvar          #+#    #+#             */
/*   Updated: 2025/11/11 13:16:06 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ate_status(t_general *data)
{
	if (all_ate(data) != 0)
	{
		pthread_mutex_lock(&data->death_lock);
		data->dead = 1;
		pthread_mutex_unlock(&data->death_lock);
	}
}

void	philo_dead(t_general *data, long long now, int i)
{
	pthread_mutex_lock(&data->death_lock);
	pthread_mutex_lock(&data->print);
	printf("%lld %d died\n", (now - data->start_time) % 100000,
		data->philo[i].id);
	data->dead = 1;
	pthread_mutex_unlock(&data->print);
	pthread_mutex_unlock(&data->death_lock);
}

long long	do_monitor(t_general *data, int i)
{
	long long	now;
	long long	last;

	now = timestamp_ms();
	pthread_mutex_lock(&data->meal_lock);
	last = data->philo[i].last_meal;
	pthread_mutex_unlock(&data->meal_lock);
	return (now - last);
}

void	*monitor(void *arg)
{
	t_general	*data;
	int			i;
	long long	time;

	data = (t_general *)arg;
	ate_status(data);
	while (!is_dead(data))
	{
		i = 0;
		while (i < data->number_of_philosophers)
		{
			time = do_monitor(data, i);
			if ((time > data->time_to_die))
			{
				philo_dead(data, timestamp_ms(), i);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

void	*ft_routine(void *arg)
{
	t_philosophers	*p;

	p = (t_philosophers *)arg;
	if (p->id % 2 == 0)
		usleep(50);
	while (!is_dead(p->data))
	{
		take_forks(p);
		eat(p);
		release_forks(p);
		sleep_philo(p);
		think(p);
	}
	return (NULL);
}
