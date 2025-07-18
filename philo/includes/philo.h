/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:39:11 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/18 11:45:14 by ifounas          ###   ########.fr       */
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

typedef struct s_philo
{
	long int		nb_philo;
	long int		death_time;
	long int		eat_time;
	long int		sleep_time;
	long int		x_repeat;
	long int		start_time;
	int				*forks_tab;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*last_eat_access;
	pthread_mutex_t	stdout_acces;
	pthread_t		*philos;
	pthread_t		track_death;
}					t_philo;

typedef struct s_philo_threads
{
	long int		start_time;
	long int		last_eat_time;
	long int		intern_x_repeat;
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

/*---------- philo_process --*/
void				*philo_track_death(void *arg);
void				philo_process(t_philo *philo,
						t_philo_threads *philo_threads);

/*---------- philo_routine_utils --*/
void				philo_threads_release_forks(t_philo_threads *philo_threads);

/*---------- philo_routine --*/
void				*philo_threads_routine(void *arg);
void				philo_routine_take_fork(t_philo_threads *philo_threads,
						int nb_fork);

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
void				set_forks(t_philo_threads *philo_threads);
long int			ft_atoi_ult(char *s, int *error);

#endif