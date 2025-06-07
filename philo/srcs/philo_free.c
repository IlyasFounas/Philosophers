/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:46:50 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/07 16:11:34 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_free_all(t_philo *philo)
{
	int i;

	i = -1;
	if (philo->forks)
	{
		while (++i < philo->nb_philo)
			pthread_mutex_destroy(&philo->forks[i]);
		free(philo->forks);
	}
    exit(0);
}
