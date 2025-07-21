/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:17:41 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/21 17:04:07 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	return_actual_time(t_philo *philo, t_philo_threads *philo_threads)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		philo_free_all(philo, NULL);
	if (philo)
		return (((time.tv_sec * 1000) + (time.tv_usec / 1000))
			- philo->start_time);
	else if (philo_threads)
		return (((time.tv_sec * 1000) + (time.tv_usec / 1000))
			- philo_threads->start_time);
	return (0);
}

void	last_eat_time(t_philo *philo, t_philo_threads *philo_threads, int index)
{
	if (philo_threads)
	{
		pthread_mutex_lock(&philo->last_eat_access[index]);
		philo_threads->last_eat_time = return_actual_time(NULL, philo_threads);
		pthread_mutex_unlock(&philo->last_eat_access[index]);
	}
	return ;
}

void	philo_init_time(t_philo *philo, t_philo_threads *philo_threads)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		philo_free_all(philo, NULL);
	if (philo)
		philo->start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (philo_threads)
		philo_threads->start_time = (time.tv_sec * 1000) + (time.tv_usec
				/ 1000);
	return ;
}

void	ms_sleep(t_philo *philo, t_philo_threads *philo_threads, int x_time)
{
	long int	start;

	start = return_actual_time(philo, philo_threads);
	while (return_actual_time(philo, philo_threads) - start < x_time)
		usleep(100);
	return ;
}
