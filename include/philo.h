/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfox <jfox.42angouleme@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:45:13 by j.fox             #+#    #+#             */
/*   Updated: 2026/10/08 15:38:09 by jfox             ###   ########.fr       */
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

typedef struct s_data	t_data;

typedef struct s_philos
{
	int				id;
	int				eaten;
	ssize_t			last_eat;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_ok;
	t_data			*data;
}	t_philos;

typedef struct s_data
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				no_to_eat;
	int				all_eaten;
	int				dead;
	ssize_t			sim_start;
	t_philos		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_ok;
	pthread_mutex_t	dead_ok;
	pthread_mutex_t	finished_ok;
	pthread_t		monitor;
}	t_data;

int		parse_args(t_data *data, int argc, char **argv);

int		ft_usleep(size_t milliseconds, t_data *data);
ssize_t	get_time(void);
void	set_time(t_data *data);

int		init_forks(t_data *data);
void	assign_forks(t_data *data);

int		create_threads(t_data *data);
void	join_thread(t_data *data);

void	death(t_data *data);
int		simulate_death(t_data *data);
void	*monitor_routine(void *arg);

int		full(t_philos *philo);
void	pickup_fork(t_philos *philo);
void	eat(t_philos *philo);
void	drop_fork(t_philos *philo);
void	philosophize_this(t_philos *philo);

void	print_output(t_philos *philo, char *output);

void	destroy_failed_forks(t_data *data, int i);
void	clean(t_data *data);

#endif
