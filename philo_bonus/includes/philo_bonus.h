/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:24:03 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/22 17:45:29 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_philo
{
	long int	nb_philo;
	long int	death_time;
	long int	eat_time;
	long int	sleep_time;
	long int	x_repeat;
	long int	start_time;
	int			pids_num;
	sem_t		*forks;
	sem_t		*write;
	sem_t		*dead;
	sem_t		*meals;
	pid_t		*pids;
	pthread_t	monitor;
}				t_philo;

/*---------- init_bonus--*/
long int		return_actual_time(t_philo *philo);
void			philo_init_time(t_philo *philo);
void			ms_sleep(t_philo *philo, int x_time);
int				ft_strlen(char *s);
void			init_bonus(t_philo *philo, char **argv);

/*---------- main_bonus--*/

/*---------- routine_bonus--*/
void			routine_bonus(t_philo *philo, int philo_nb);

/*---------- simulation_bonus--*/
void			launch_simulation(t_philo *philo);

/*---------- utils_bonus--*/
void			clean_simulation(t_philo *philo);
void			init_exit(char *s);
long int		ft_atoi_ult(char *s, int *error);

#endif