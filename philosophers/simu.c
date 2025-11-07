/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:59:41 by pabalvar          #+#    #+#             */
/*   Updated: 2025/11/07 17:38:34 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*monitor(void *arg)
{
	t_general	*data;
	int			i;
	long long	now;

	data = (t_general *)arg;
	ate_status(data);
	while (!data->dead)
	{
		i = 0;
		while (i < data->number_of_philosophers)
		{
			now = timestamp_ms();
			if ((now - data->philo[i].last_meal > data->time_to_die))
			{
				philo_dead(data, now, i);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

void	philo_dead(t_general	*data, long long now, int i)
{
	pthread_mutex_lock(&data->print);
	printf("%lld %d died\n", (now
			- data->start_time) % 100000, data->philo[i].id);
	data->dead = 1;
	pthread_mutex_unlock(&data->print);
}

void	*ft_routine(void *arg)
{
	t_philosophers	*p;

	p = (t_philosophers *)arg;
	printf("[DEBUG] Thread %ld (Philo %d) creado\n", pthread_self(), p->id);
	if (p->id % 2 == 0)
		usleep(50);
	while (!p->data->dead)
	{
		take_forks(p);
		eat(p);
		release_forks(p);
		sleep_philo(p);
		think(p);
	}
	printf("[DEBUG] Thread %ld (Philo %d) terminado\n", pthread_self(), p->id);
	return (NULL);
}

int	all_ate(t_general *data)
{
	int		ate;
	int		i;
	int		j;

	ate = 0;
	i = 0;
	j = 0;
	if (data->number_of_times_each_philosopher_must_eat == -1)
		return (ate);
	while (i < data->number_of_philosophers)
	{
		if (data->philo[i].times_eaten
			>= data->number_of_times_each_philosopher_must_eat)
			j++;
		i++;
	}
	if (j == data->number_of_philosophers)
		ate++;
	return (ate);
}

void	ate_status(t_general *data)
{
	if (all_ate(data) != 0)
	{
		pthread_mutex_lock(&data->meal_lock);
		data->dead = 1;
		pthread_mutex_unlock(&data->meal_lock);
	}
}
