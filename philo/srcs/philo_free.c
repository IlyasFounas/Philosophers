/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:46:50 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/21 16:03:50 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void destroy_mutex(t_philo *philo, t_philo_threads *philo_threads)
{
	int i;

	i = -1;
	if (philo_threads)
		pthread_mutex_destroy(&philo_threads->meals_mut);
	if (philo->forks)
	{
		while (++i < philo->nb_philo)
			pthread_mutex_destroy(&philo->forks[i]);
		free(philo->forks);
	}
	if (philo->last_eat_access)
		free(philo->last_eat_access);
}

void	philo_free_all(t_philo *philo, t_philo_threads *philo_threads)
{
	int	i;
	
	i = -1;
	if (philo->philos)
		free(philo->philos);
	if (philo->forks_tab)
		free(philo->forks_tab);
	destroy_mutex(philo, philo_threads);
	if (philo_threads)
		free(philo_threads);
	exit(0);
}

