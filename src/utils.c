/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j.fox <jfox.42angouleme@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 14:12:26 by jfox              #+#    #+#             */
/*   Updated: 2026/10/07 19:33:23 by j.fox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_output(t_philos *philo, char *output)
{
	ssize_t	time;

	time = get_time() - philo->data->sim_start;
	pthread_mutex_lock(&philo->data->print_ok);
	printf("%zd %d %s\n", time, philo->id, output);
	pthread_mutex_unlock(&philo->data->print_ok);
}
