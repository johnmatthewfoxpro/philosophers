/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 16:08:28 by j.fox             #+#    #+#             */
/*   Updated: 2026/10/06 16:10:19 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;

	while (!philo->data->dead)
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
		// pthread_mutex_lock(philo->left_fork);
		// print_output(philo, "has taken a fork");
		// pthread_mutex_lock(philo->right_fork);
		// print_output(philo, "has taken a fork");
		pthread_mutex_lock(&philo->meal_ok);
		philo->last_eat = get_time();
		pthread_mutex_unlock(&philo->meal_ok);
		print_output(philo, "is eating");
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		print_output(philo, "is sleeping");
		usleep(philo->data->time_to_sleep * 1000);
		print_output(philo, "is thinking");
	}
	return (NULL);
}

void	join_thread(t_data *data)
{
	int	i;

	i = 0;
	pthread_join(data->monitor, NULL);
	while(i < data->number_of_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philo_routine, &data->philos[i]))
			return (1);
		i++;
	}
	if (pthread_create(&data->monitor, NULL, monitor_routine, &data))
		return (1);
	return (0);
}
