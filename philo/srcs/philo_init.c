/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:32:22 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/10 17:02:55 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_init(t_philo *philo)
{
	int	i;

	i = -1;
	philo->forks = malloc((philo->nb_philo) * sizeof(pthread_mutex_t));
	if (!philo->forks)
		free_philo(philo, 1);
	while (++i < philo->nb_philo)
		pthread_mutex_init(&philo->forks[i], NULL);
	return ;
}

void	threads_init(t_philo *philo)
{
	int	i;

	i = -1;
	philo->philos = malloc((philo->nb_philo) * sizeof(pthread_t));
	if (!philo->philos)
		free_philo(philo, 1);
	while (++i < philo->nb_philo)
		if (pthread_create(&philo->philos[i], NULL, manage_threads, philo) != 0)
			free_philo(philo, 1);
	i = -1;
	while (++i < philo->nb_philo)
		if (pthread_join(philo->philos[i], NULL) != 0)
			free_philo(philo, 1);
	return ;
}
