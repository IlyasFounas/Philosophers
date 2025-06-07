/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:05:16 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/07 16:05:16 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_init_mutex(t_philo *philo)
{
	int i;

	i = -1;

	philo->forks = malloc(philo->nb_philo * sizeof(pthread_mutex_t));
	if (!philo->forks)
		philo_free_all(philo);
	while (++i < philo->nb_philo)
		if (pthread_mutex_init(&philo->forks[i], NULL) == -1)
			philo_free_all(philo);
}

void	philo_init(t_philo *philo, char **argv)
{
	int error;

	error = 0;
	philo->nb_philo = ft_atoi_ult(argv[1], &error);
	philo->death_time = ft_atoi_ult(argv[2], &error);
	philo->eat_time = ft_atoi_ult(argv[3], &error);
	philo->sleep_time = ft_atoi_ult(argv[4], &error);
	if (argv[5])
		philo->x_repeat = ft_atoi_ult(argv[5], &error);
	if (error == 1)
	{
		printf("long int overflow\n");
		exit(0);
	}
	philo_init_mutex(philo);
}

void philo_init_threads(t_philo *philo)
{

}
