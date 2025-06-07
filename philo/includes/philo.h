/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:39:11 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/07 16:11:28 by ifounas          ###   ########.fr       */
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
	pthread_mutex_t	*forks;
}					t_philo;

// philo_free
void				philo_free_all(t_philo *philo);

// philo_init
void				philo_init(t_philo *philo, char **argv);
void				philo_init_threads(t_philo *philo);

// philo_process
void				philo_process(t_philo *philo);

// philo_utils
long int			ft_atoi_ult(char *s, int *error);

#endif