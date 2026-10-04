/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j.fox <jfox.42angouleme@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 16:08:28 by j.fox             #+#    #+#             */
/*   Updated: 2026/09/27 16:08:28 by j.fox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_routine(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	return (NULL);

	// pthread_mutex_lock(philo->left_fork);
	// print_status(philo, "has taken a fork");

	// pthread_mutex_lock(philo->right_fork);
	// print_status(philo, "has taken a fork");

	// print_status(philo, "is eating");

	// usleep(data->time_to_eat * 1000);

	// pthread_mutex_unlock(philo->right_fork);
	// pthread_mutex_unlock(philo->left_fork);
}

void	join_thread(t_data *data)
{
	int	i;

	i = 0;
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
	return (0);
}

