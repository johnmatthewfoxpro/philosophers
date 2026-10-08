/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:12:26 by jfox              #+#    #+#             */
/*   Updated: 2026/10/08 15:40:37 by jfox             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_output(t_philos *philo, char *output)
{
	ssize_t	time;

	if (simulate_death(philo->data) || philo->data->all_eaten)
		return ;
	time = get_time() - philo->data->sim_start;
	pthread_mutex_lock(&philo->data->print_ok);
	printf("%zd %d %s\n", time, philo->id, output);
	pthread_mutex_unlock(&philo->data->print_ok);
}
