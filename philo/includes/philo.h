/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:45:33 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/11 14:48:44 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	int				death;
	struct timeval	time;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	suseconds_t		start;
}					t_philo;

typedef struct s_philo_thread
{
	int				philo_id;
	t_philo			*philo;
}					t_philo_thread;

// philo_atoi
long int			ft_atoi_error(const char *nptr);

// philo_check
void				check_args(int args);
void				check_infos(t_philo *philo);

// philo_free
void				free_philo(t_philo *philo, int exit_code);

// philo_init
void				time_init(t_philo *philo);
void				forks_init(t_philo *philo);
void				threads_init(t_philo *philo);

// philo_manage
void				*manage_threads(void *arg);

#endif