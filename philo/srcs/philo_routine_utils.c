/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:27:30 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/26 16:14:33 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	stdout_open(t_philo *philo)
{
	pthread_mutex_lock(&philo->all_mutex.dead_philo_mut);
	if (philo->dead_philo == 1)
	{
		pthread_mutex_unlock(&philo->all_mutex.dead_philo_mut);
		return (0);
	}
	pthread_mutex_unlock(&philo->all_mutex.dead_philo_mut);
	return (1);
}

void	philo_threads_release_forks(t_philo_threads *philo_threads)
{
	t_philo_mut	*all_mutex;

	all_mutex = &philo_threads->philo->all_mutex;
	set_forks(philo_threads);
	philo_threads->philo->forks_tab[philo_threads->fork1] = 1;
	philo_threads->philo->forks_tab[philo_threads->fork2] = 1;
	pthread_mutex_unlock(&all_mutex->forks[philo_threads->fork1]);
	pthread_mutex_unlock(&all_mutex->forks[philo_threads->fork2]);
}

void	philo_routine_take_fork(t_philo_threads *philo_threads, int nb_fork)
{
	t_philo_mut	*all_mutex;

	all_mutex = &philo_threads->philo->all_mutex;
	pthread_mutex_lock(&all_mutex->forks[nb_fork]);
	philo_threads->philo->forks_tab[nb_fork] = 0;
	if (stdout_open(philo_threads->philo) == 1)
	{
		pthread_mutex_lock(&all_mutex->stdout_acces);
		printf("%ld %d has taken a fork\n", return_actual_time(NULL,
				philo_threads), philo_threads->thread_nb);
		pthread_mutex_unlock(&all_mutex->stdout_acces);
	}
}
