/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j.fox <jfox.42angouleme@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:45:13 by j.fox             #+#    #+#             */
/*   Updated: 2026/09/25 17:45:13 by j.fox            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

typedef struct	s_data	t_data;

typedef struct	s_philos
{
	int				id;
	int				eaten;
	size_t			last_eat;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philos;

typedef struct	s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				no_to_eat;
	t_philos			*philos;
	pthread_mutex_t	*forks;
	//mutexes
	//timing
}	t_data;

int		parse_args(t_data *data, int argc, char **argv);

int		create_threads(t_data *data);
void	join_thread(t_data *data);

int		init_forks(t_data *data);
void	assign_forks(t_data *data);

void	destroy_failed_forks(t_data *data, int i);
void	clean(t_data *data);

#endif