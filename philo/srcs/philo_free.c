/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:46:50 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/21 11:07:32 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_free_all(t_philo *philo, t_philo_threads *philo_threads)
{
	int	i;
	// int	j;

	// j = -1;
	i = -1;
	if (philo->forks)
	{
		while (++i < philo->nb_philo)
			pthread_mutex_destroy(&philo->forks[i]);
		free(philo->forks);
	}
	if (philo->philos)
		free(philo->philos);
	if (philo->forks_tab)
		free(philo->forks_tab);
	if (philo_threads)
		free(philo_threads);
	exit(1);
}

