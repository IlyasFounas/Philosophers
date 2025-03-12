/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:43:33 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/12 11:39:14 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo *philo, int exit_code)
{
	if (philo->philos)
	{
		free(philo->philos);
		philo->philos = NULL;
	}
	if (philo->forks)
	{
		if (philo->nb_philo > 0)
			pthread_mutex_destroy(philo->forks);
		free(philo->forks);
	}
	exit(exit_code);
}

void	free_threads(t_philo *philo, int exit_code)
{
	int	i;

	i = -1;
	while (++i < philo->nb_philo)
		if (pthread_join(philo->philos[i], NULL) != 0)
			free_philo(philo, 1);
	free_philo(philo, exit_code);
}
