/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:46:50 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/21 17:00:34 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutex(t_philo *philo, t_philo_threads *philo_threads)
{
	int	i;

	i = -1;
	if (philo->stdout_mut_failed == 0)
		pthread_mutex_destroy(&philo->stdout_acces);
	if (philo->simulation_mut_failed == 0)
		pthread_mutex_destroy(&philo->stop_simulation_mut);
	if (philo_threads)
		pthread_mutex_destroy(&philo_threads->meals_mut);
	if (philo->forks && philo->last_eat_access)
	{
		while (++i < philo->nb_philo)
			pthread_mutex_destroy(&philo->forks[i]);
		i = -1;
		while (++i < philo->nb_philo)
			pthread_mutex_destroy(&philo->last_eat_access[i]);
	}
}

void	philo_free_all(t_philo *philo, t_philo_threads *philo_threads)
{
	int	i;

	i = -1;
	destroy_mutex(philo, philo_threads);
	if (philo->philos)
		free(philo->philos);
	if (philo->forks_tab)
		free(philo->forks_tab);
	if (philo->forks)
		free(philo->forks);
	if (philo->last_eat_access)
		free(philo->last_eat_access);
	if (philo_threads)
		free(philo_threads);
	exit(0);
}
