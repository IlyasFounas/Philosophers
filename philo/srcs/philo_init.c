/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:32:22 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/08 16:24:31 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo *philo, int exit_code)
{
	if (philo->forks)
		free(philo->forks);
    free(philo->philos);
    philo->philos = NULL;
	exit(exit_code);
}

void	forks_init(t_philo *philo)
{
	int	i;

	i = -1;
	philo->forks = malloc((philo->nb_philo) * sizeof(int));
	if (!philo->forks)
		return ;
	while (++i < philo->nb_philo)
		philo->forks[i] = 1;
	return ;
}

void *manage_threads(void *arg) 
{
    static int i = 0;
    (void)arg;
    // t_philo *philo = (t_philo *)arg;
    
    i++;
    printf("%d\n", i);
    return NULL;
}

void	threads_init(t_philo *philo)
{
	int	i;

	i = -1;
	philo->philos = malloc((philo->nb_philo) * sizeof(pthread_t));
	if (!philo->philos)
		free_philo(philo, 1);
	while (++i < philo->nb_philo)
	{
		if (pthread_create(&philo->philos[i], NULL, manage_threads, NULL) != 0)
            free_philo(philo, 1);
	}
	i = -1;
	while (++i < philo->nb_philo)
	{
		if (pthread_join(philo->philos[i], NULL) != 0)
            free_philo(philo, 1);
        i++;
	}
	return ;
}
