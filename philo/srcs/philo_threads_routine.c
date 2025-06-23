/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads_routine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:23:25 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/23 18:15:04 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void philo_threads_eating(t_philo_threads *philo_threads)
{
	pthread_mutex_lock(&philo_threads->philo->stdout_acces);
	printf("%ld %d is eating\n", return_actual_time(NULL, philo_threads),
		philo_threads->thread_nb);
	pthread_mutex_unlock(&philo_threads->philo->stdout_acces);
}


static void	philo_threads_take_forks(t_philo_threads *philo_threads)
{
    pthread_mutex_lock(&philo_threads->philo->stdout_acces);
	
    pthread_mutex_unlock(&philo_threads->philo->stdout_acces);
	pthread_mutex_lock(&philo_threads->philo->stdout_acces);
	printf("%ld %d has taken a fork\n", return_actual_time(NULL, philo_threads),
		philo_threads->thread_nb);
	pthread_mutex_unlock(&philo_threads->philo->stdout_acces);
}

void	*philo_threads_routine(void *arg)
{
	t_philo_threads	*philo_threads;
	int				eated;

	eated = 0;
	philo_threads = arg;
	philo_init_time(NULL, philo_threads);
	while (eated != philo_threads->intern_x_repeat)
	{
		philo_threads_take_forks(philo_threads);
		philo_threads_eating(philo_threads);
		ms_sleep(NULL, philo_threads, 1000/* philo_threads->philo->eat_time */);
		eated++;
	}
	return (NULL);
}
