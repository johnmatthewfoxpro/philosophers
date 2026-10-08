/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 16:08:28 by j.fox             #+#    #+#             */
/*   Updated: 2026/10/08 15:15:17 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	single_philo(t_philos *philo)
{
	print_output(philo, "has taken a fork");
	ft_usleep(philo->data->time_to_die, philo->data);
	print_output(philo, "died");
}

static void	*philo_routine(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (!simulate_death(philo->data) && !philo->data->all_eaten)
	{
		pickup_fork(philo);
		eat(philo);
		drop_fork(philo);
		philosophize_this(philo);
	}
	return (NULL);
}

void	join_thread(t_data *data)
{
	int	i;

	i = 0;
	pthread_join(data->monitor, NULL);
	while (i < data->number_of_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	if (data->number_of_philos == 1)
	{
		single_philo(&data->philos[i]);
		return (0);
	}
	while (i < data->number_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, philo_routine,
				&data->philos[i]))
			return (1);
		i++;
	}
	if (pthread_create(&data->monitor, NULL, monitor_routine, data))
		return (1);
	return (0);
}
