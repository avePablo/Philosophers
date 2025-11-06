/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalvar <pabalvar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:59:20 by pabalvar          #+#    #+#             */
/*   Updated: 2025/11/05 20:59:20 by pabalvar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_philosophers *p)
{
	if (p->id % 2 != 0)
	{
		pthread_mutex_lock(&p->data->forks[p->fork_r]);
		print_state(p, "has taken a fork");
		pthread_mutex_lock(&p->data->forks[p->fork_l]);
		print_state(p, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&p->data->forks[p->fork_l]);
		print_state(p, "has taken a fork");
		pthread_mutex_lock(&p->data->forks[p->fork_r]);
		print_state(p, "has taken a fork");
	}
}

void	release_forks(t_philosophers *p)
{
	pthread_mutex_unlock(&p->data->forks[p->fork_l]);
	pthread_mutex_unlock(&p->data->forks[p->fork_r]);
}

void	eat(t_philosophers *p)
{
	if (all_ate(p->data) == 0)
	{
		print_state(p, "is eating");
		p->last_meal = timestamp_ms();
		if (p->data->number_of_times_each_philosopher_must_eat != -1)
		{
			pthread_mutex_lock(&p->data->meal_lock);
			p->times_eaten++;
			pthread_mutex_unlock(&p->data->meal_lock);
		}
		smart_sleep(p->data->time_to_eat, p->data);
	}
}

void	sleep_philo(t_philosophers *p)
{
	print_state(p, "is sleeping");
	smart_sleep(p->data->time_to_sleep, p->data);
}

void	think(t_philosophers *p)
{
	print_state(p, "is thinking");
}
