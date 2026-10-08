/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 15:55:51 by j.fox             #+#    #+#             */
/*   Updated: 2026/10/08 15:38:56 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_failed_forks(t_data *data, int i)
{
	while (i > 0)
	{
		i--;
		pthread_mutex_destroy(&data->forks[i]);
	}
	free(data->forks);
	return ;
}

void	clean(t_data *data)
{
	int	i;

	i = 0;
	if (data->forks)
	{
		while (i < data->number_of_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			pthread_mutex_destroy(&data->philos[i].meal_ok);
			i++;
		}
		free(data->forks);
	}
	if (data->philos)
		free(data->philos);
	pthread_mutex_destroy(&data->print_ok);
	pthread_mutex_destroy(&data->dead_ok);
	pthread_mutex_destroy(&data->finished_ok);
	return ;
}
