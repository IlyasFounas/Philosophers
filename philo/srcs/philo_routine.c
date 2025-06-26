/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:27:25 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/26 19:01:29 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_threads_eating(t_philo_threads *philo_threads)
{
	set_forks(philo_threads);
	philo_routine_take_fork(philo_threads, philo_threads->fork1);
	philo_routine_take_fork(philo_threads, philo_threads->fork2);
	pthread_mutex_lock(&philo_threads->philo->stdout_acces);
	printf("%ld %d is eating\n", return_actual_time(NULL, philo_threads),
		philo_threads->thread_nb);
	pthread_mutex_unlock(&philo_threads->philo->stdout_acces);
	ms_sleep(NULL, philo_threads, philo_threads->philo->eat_time);
	philo_threads_release_forks(philo_threads);
}

static void philo_threads_sleeping(t_philo_threads *philo_threads)
{
	pthread_mutex_lock(&philo_threads->philo->stdout_acces);
	printf("%ld %d is sleeping\n", return_actual_time(NULL, philo_threads),
		philo_threads->thread_nb);
	pthread_mutex_unlock(&philo_threads->philo->stdout_acces);
	ms_sleep(NULL, philo_threads, philo_threads->philo->sleep_time);
}

static void philo_threads_thinking(t_philo_threads *philo_threads)
{
	return ;
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
		philo_threads_eating(philo_threads);
		philo_threads_sleeping(philo_threads);
		philo_threads_thinking(philo_threads);
		eated++;
	}
	return (NULL);
}
