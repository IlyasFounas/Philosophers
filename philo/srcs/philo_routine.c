/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:27:25 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/18 11:45:38 by ifounas          ###   ########.fr       */
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
	pthread_mutex_lock(philo_threads->philo->last_eat_access);
	philo_threads->last_eat_time = return_actual_time(NULL, philo_threads);
	pthread_mutex_unlock(philo_threads->philo->last_eat_access);
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
	pthread_mutex_lock(&philo_threads->philo->stdout_acces);
	printf("%ld %d is thinking\n", return_actual_time(NULL, philo_threads),
		philo_threads->thread_nb);
	pthread_mutex_unlock(&philo_threads->philo->stdout_acces);
}

void	*philo_threads_routine(void *arg)
{
	t_philo_threads	*philo_threads;
	
	philo_threads = arg;
	philo_init_time(NULL, philo_threads);
	while (42)
	{
		philo_threads_eating(philo_threads);
		pthread_mutex_lock(&philo_threads->meals_mut);
		philo_threads->meals++;
		pthread_mutex_unlock(&philo_threads->meals_mut);
		philo_threads_sleeping(philo_threads);
		philo_threads_thinking(philo_threads);
	}
	return (NULL);
}
