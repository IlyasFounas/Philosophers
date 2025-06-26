/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:27:30 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/26 18:47:23 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_threads_release_forks(t_philo_threads *philo_threads)
{
	set_forks(philo_threads);
	philo_threads->philo->forks_tab[philo_threads->fork1] = 1;
	philo_threads->philo->forks_tab[philo_threads->fork2] = 1;
	pthread_mutex_unlock(&philo_threads->philo->forks[philo_threads->fork1]);
	pthread_mutex_unlock(&philo_threads->philo->forks[philo_threads->fork2]);
}

void philo_routine_take_fork(t_philo_threads *philo_threads, int nb_fork)
{
	pthread_mutex_lock(&philo_threads->philo->forks[nb_fork]);
	philo_threads->philo->forks_tab[nb_fork] = 0;
	pthread_mutex_lock(&philo_threads->philo->stdout_acces);
	printf("%ld %d has taken a fork\n", return_actual_time(NULL, philo_threads),
		philo_threads->thread_nb);
	pthread_mutex_unlock(&philo_threads->philo->stdout_acces);
}
