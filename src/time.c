/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 13:11:22 by jfox              #+#    #+#             */
/*   Updated: 2026/10/08 14:16:20 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

ssize_t	get_time(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return ((tp.tv_sec * 1000) + (tp.tv_usec / 1000));
}

void	set_time(t_data *data)
{
	int	i;

	i = 0;
	data->sim_start = get_time();
	while (i < data->number_of_philos)
	{
		data->philos[i].last_eat = data->sim_start;
		i++;
	}
	return ;
}

int	ft_usleep(size_t milliseconds, t_data *data)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
	{
		if (simulate_death(data))
			return (1);
		usleep(200);
	}
	return (0);
}
