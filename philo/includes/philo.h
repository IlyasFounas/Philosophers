/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:39:11 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/29 13:24:54 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_philo_mut
{
	int				simulation_mut_failed;
	int				stdout_mut_failed;
	int				dead_mut_failed;
	int				start_mut_failed;
	int				threads_mut_failed;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*last_eat_access;
	pthread_mutex_t	dead_philo_mut;
	pthread_mutex_t	stdout_acces;
	pthread_mutex_t	threads_mut;
	pthread_mutex_t	stop_simulation_mut;
	pthread_mutex_t	start_simulation_mut;
}					t_philo_mut;

typedef struct s_philo
{
	long int		nb_philo;
	long int		death_time;
	long int		eat_time;
	long int		sleep_time;
	long int		x_repeat;
	long int		start_time;
	int				*forks_tab;
	int				stop_simualtion;
	int				dead_philo;
	int				exit_option;
	int				all_threads_ready;
	pthread_t		*philos;
	t_philo_mut		all_mutex;
}					t_philo;

typedef struct s_philo_threads
{
	long int		start_time;
	long int		last_eat_time;
	long int		meals;
	int				thread_nb;
	int				fork1;
	int				fork2;
	pthread_mutex_t	meals_mut;
	t_philo			*philo;
}					t_philo_threads;

/*---------- philo_free --*/
void				philo_free_all(t_philo *philo,
						t_philo_threads *philo_threads);

/*---------- philo_init --*/
void				philo_init_tab(t_philo *philo,
						t_philo_threads **philo_threads);
void				philo_init(t_philo *philo, char **argv);
void				philo_init_threads(t_philo *philo,
						t_philo_threads *philo_threads);

/*---------- philo_main --*/
void				error_msg(t_philo *philo, char *x_repeat);

/*---------- philo_process --*/
void				philo_monitor(t_philo_threads *philo_threads);
void				philo_process(t_philo *philo,
						t_philo_threads *philo_threads);

/*---------- philo_routine_utils --*/
int					stdout_open(t_philo *philo);
void				philo_threads_release_forks(t_philo_threads *philo_threads);
void				philo_routine_take_fork(t_philo_threads *philo_threads,
						int nb_fork);

/*---------- philo_routine --*/
void				*philo_threads_routine(void *arg);

/*---------- philo_time --*/
long int			return_actual_time(t_philo *philo,
						t_philo_threads *philo_threads);
void				last_eat_time(t_philo *philo,
						t_philo_threads *philo_threads, int index);
void				philo_init_time(t_philo *philo,
						t_philo_threads *philo_threads);
void				ms_sleep(t_philo *philo, t_philo_threads *philo_threads,
						int x_time);

/*---------- philo_utils --*/
void				philo_init_mutex(t_philo *philo, int i);
void				set_forks(t_philo_threads *philo_threads);
long int			ft_atoi_ult(char *s, int *error);

#endif