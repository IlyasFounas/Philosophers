/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:39:11 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/07 18:51:16 by ifounas          ###   ########.fr       */
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
	struct timeval	*time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	stdout_acces;
	pthread_t		*philos;
}					t_philo;

typedef struct s_philo_threads
{
	int				thread_nb;
	t_philo			*philo;
}					t_philo_threads;

// philo_free
void				philo_free_all(t_philo *philo,
						t_philo_threads *philo_threads);

// philo_init
void				philo_init_tab(t_philo *philo,
						t_philo_threads **philo_threads);
void				philo_init(t_philo *philo, char **argv);
void				philo_init_threads(t_philo *philo,
						t_philo_threads *philo_threads);

// philo_process
void				philo_process(t_philo *philo,
						t_philo_threads *philo_threads);

// philo_main

// philo_threads_routine
void				*philo_threads_routine(void *arg);

// philo_utils
long int			ft_atoi_ult(char *s, int *error);
void				ms_sleep(int x_time);

#endif