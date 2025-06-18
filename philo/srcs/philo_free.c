/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:46:50 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/18 13:56:37 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
	if (philo_threads)
		free(philo_threads);
	exit(0);
}
