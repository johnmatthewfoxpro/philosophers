/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:18:36 by j.fox             #+#    #+#             */
/*   Updated: 2026/10/08 15:54:50 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	full(t_philos *philo)
{
	if (philo->data->no_to_eat == -1)
		return (0);
	if (philo->eaten >= philo->data->no_to_eat)
		return (1);
	return (0);
}

void	pickup_fork(t_philos *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_output(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_output(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_output(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_output(philo, "has taken a fork");
	}
}

void	eat(t_philos *philo)
{
	pthread_mutex_lock(&philo->meal_ok);
	philo->last_eat = get_time();
	philo->eaten += 1;
	pthread_mutex_unlock(&philo->meal_ok);
	print_output(philo, "is eating");
	ft_usleep(philo->data->time_to_eat, philo->data);
}

void	drop_fork(t_philos *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	philosophize_this(t_philos *philo)
{
	print_output(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep, philo->data);
	print_output(philo, "is thinking");
}
