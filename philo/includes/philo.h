/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:45:33 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/08 16:17:20 by ifounas          ###   ########.fr       */
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

typedef struct s_philo
{
	int				nb_philo;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				death;
	int				*forks;
	struct timeval	time;
	pthread_t		*philos;
}					t_philo;

// philo_check
void				check_args(int args);

// philo_free
void				free_philo(t_philo *philo, int exit_code);

// philo_init
void				forks_init(t_philo *philo);
void				threads_init(t_philo *philo);

// philo_utils
long int			ft_atoi_error(const char *nptr);

#endif