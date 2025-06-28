/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:07:27 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/28 19:40:45 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_track_death(void *arg)
{
	int				i;
	int				j;
	t_philo_threads	*philo_threads;

	i = 0;
	j = -1;
	philo_threads = arg;
	while (42)
	{
		pthread_mutex_lock(philo_threads->philo->last_eat_access);
		if (return_actual_time(NULL, &philo_threads[i])
			- philo_threads[i].last_eat_time > philo_threads->philo->death_time)
		{
			write(2, "someone died\n", 13);
			while (++j < philo_threads->philo->nb_philo)
				pthread_join(philo_threads->philo->philos[j], NULL);
			pthread_mutex_unlock(philo_threads->philo->last_eat_access);
			exit(0);
		}
		pthread_mutex_unlock(philo_threads->philo->last_eat_access);
		i++;
		if (i >= philo_threads->philo->nb_philo)
			i = 0;
	}
}

void	philo_process(t_philo *philo, t_philo_threads *philo_threads)
{
	if (philo->nb_philo == 1 || philo->nb_philo == 0)
	{
		ms_sleep(philo, NULL, philo->death_time);
		printf("philo nb 1 has died");
		philo_free_all(philo, philo_threads);
	}
	philo_init_threads(philo, philo_threads);
}
