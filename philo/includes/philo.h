/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:39:11 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/19 10:49:41 by ifounas          ###   ########.fr       */
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
	long int		think_time;
	long int		many_times;
	int				death;
	struct timeval	time;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	suseconds_t		start;
}					t_philo;

typedef struct s_philo_thread
{
	int				philo_id;
	long int		last_meal;
	int				died;
	struct timeval	time;
	t_philo			*philo;
}					t_philo_thread;

// philo_atoi
long int			ft_atoi_error(const char *nptr);

// philo_check
void				check_args(int args);
void				check_infos(t_philo *philo);
void				check_someone_died(t_philo *philo, t_philo_thread *threads);

// philo_free
void				free_philo(t_philo *philo, int exit_code);
void				free_threads(t_philo_thread *thread, t_philo *philo,
						int exit_code);

// philo_init
void				philo_init(t_philo *philo, long int nb_philo,
						long int death_time, long int eat_time);
void				time_init(t_philo *philo);
void				time_init_thread(t_philo_thread *thread);
void				forks_init(t_philo *philo);
void				threads_init(t_philo *philo);

// philo_manage
void				*manage_threads(void *arg);

// philo
long int			get_absolute_time(long int t1, long int t2);

#endif