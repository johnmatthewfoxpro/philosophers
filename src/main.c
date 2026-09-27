/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j.fox <jfox.42angouleme@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:45:19 by j.fox             #+#    #+#             */
/*   Updated: 2026/09/25 17:45:19 by j.fox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_data(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philos) * data->number_of_philos);
	if (!data->philos)
		return (1);
	while (i < data->number_of_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].eaten = 0;
		data->philos[i].last_eat = 0;
		data->philos[i].data = data;
		i++;
	}
	return (0);
}

static int	init_sim(t_data *data)
{
	if (init_data(data))
		return (1);
	if (init_forks(data))
		return (1);
	assign_forks(data);
	return (0);
}

int	main(int argc, char **argv)
{	
	t_data	data;

	if (argc < 5 || argc > 6)
		return (0);
	if (parse_args(&data, argc, argv))
		return (1);
	if (init_sim(&data))
		return (1);
	if (create_threads(&data))
		return (1);
	// run simulation

	// printf("%d\n", data.number_of_philos);
	// printf("%d\n", data.time_to_die);
	// printf("%d\n", data.time_to_eat);
	// printf("%d\n", data.time_to_sleep);
	// printf("%d\n", data.no_to_eat);
	// printf("%d\n", data.philos[0].id);
	// printf("%d\n", data.philos[1].id);

	clean(&data);
	return (0);	
}
