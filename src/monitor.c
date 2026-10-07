/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j.fox <jfox.42angouleme@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 16:09:43 by jfox              #+#    #+#             */
/*   Updated: 2026/10/07 19:29:05 by j.fox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	simulate_death(t_data *data)
{
	int	death;
	pthread_mutex_lock(&data->dead_ok);
	death = data->dead;
	pthread_mutex_unlock(&data->dead_ok);
	return (death);
}

void	death(t_data *data)
{
	pthread_mutex_lock(&data->dead_ok);
	data->dead = 1;
	pthread_mutex_unlock(&data->dead_ok);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;
	ssize_t	last_eat;

	data = (t_data *)arg;
	while (!simulate_death(data))
	{
		i = 0;
		while(i < data->number_of_philos)
		{
			pthread_mutex_lock(&data->philos[i].meal_ok);
			last_eat = data->philos[i].last_eat;
			pthread_mutex_unlock(&data->philos[i].meal_ok);
			if (get_time() - last_eat > data->time_to_die)
			{
				print_output(&data->philos[i], "died");
				death(data);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
