/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:27:25 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/26 16:15:00 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_threads_eating(t_philo_threads *philo_threads)
{
	t_philo_mut	*all_mutex;

	all_mutex = &philo_threads->philo->all_mutex;
	set_forks(philo_threads);
	philo_routine_take_fork(philo_threads, philo_threads->fork1);
	philo_routine_take_fork(philo_threads, philo_threads->fork2);
	if (stdout_open(philo_threads->philo) == 1)
	{
		pthread_mutex_lock(&philo_threads->philo->all_mutex.stdout_acces);
		printf("%ld %d is eating\n", return_actual_time(NULL, philo_threads),
			philo_threads->thread_nb);
		pthread_mutex_unlock(&philo_threads->philo->all_mutex.stdout_acces);
		pthread_mutex_lock(&all_mutex->last_eat_access[philo_threads->thread_nb
			- 1]);
		philo_threads->last_eat_time = return_actual_time(NULL, philo_threads);
		pthread_mutex_unlock(
			&all_mutex->last_eat_access[philo_threads->thread_nb
			- 1]);
		ms_sleep(NULL, philo_threads, philo_threads->philo->eat_time);
	}
	philo_threads_release_forks(philo_threads);
	pthread_mutex_lock(&philo_threads->meals_mut);
	philo_threads->meals++;
	pthread_mutex_unlock(&philo_threads->meals_mut);
}

static void	philo_threads_sleeping(t_philo_threads *philo_threads)
{
	if (stdout_open(philo_threads->philo) == 1)
	{
		pthread_mutex_lock(&philo_threads->philo->all_mutex.stdout_acces);
		printf("%ld %d is sleeping\n", return_actual_time(NULL, philo_threads),
			philo_threads->thread_nb);
		pthread_mutex_unlock(&philo_threads->philo->all_mutex.stdout_acces);
		ms_sleep(NULL, philo_threads, philo_threads->philo->sleep_time);
	}
}

static void	philo_threads_thinking(t_philo_threads *philo_threads)
{
	if (stdout_open(philo_threads->philo) == 1)
	{
		pthread_mutex_lock(&philo_threads->philo->all_mutex.stdout_acces);
		printf("%ld %d is thinking\n", return_actual_time(NULL, philo_threads),
			philo_threads->thread_nb);
		pthread_mutex_unlock(&philo_threads->philo->all_mutex.stdout_acces);
	}
}

void	*philo_threads_routine(void *arg)
{
	t_philo_threads	*philo_threads;
	t_philo_mut		*all_mutex;

	philo_threads = arg;
	all_mutex = &philo_threads->philo->all_mutex;
	while (42)
	{
		philo_threads_eating(philo_threads);
		pthread_mutex_lock(&all_mutex->stop_simulation_mut);
		if (philo_threads->philo->stop_simualtion == 1)
		{
			pthread_mutex_unlock(&all_mutex->stop_simulation_mut);
			break ;
		}
		pthread_mutex_unlock(&all_mutex->stop_simulation_mut);
		philo_threads_sleeping(philo_threads);
		pthread_mutex_lock(&all_mutex->stop_simulation_mut);
		philo_threads_thinking(philo_threads);
		pthread_mutex_unlock(&all_mutex->stop_simulation_mut);
	}
	return (NULL);
}
