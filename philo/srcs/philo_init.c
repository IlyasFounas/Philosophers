/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:32:22 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/20 10:24:57 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_philo *philo, long int nb_philo, long int death_time,
		long int eat_time)
{
	time_init(philo);
	philo->start = philo->time.tv_sec * 1000 + philo->time.tv_usec / 1000;
	philo->nb_philo = nb_philo;
	philo->death_time = death_time;
	philo->eat_time = eat_time;
}

void	time_init(t_philo *philo)
{
	if (gettimeofday(&philo->time, NULL) == -1)
		free_philo(philo, 1);
	return ;
}

void	time_init_thread(t_philo_thread *thread)
{
	if (gettimeofday(&thread->time, NULL) == -1)
		free_philo(thread->philo, 1);
	return ;
}

void	forks_init(t_philo *philo)
{
	int	i;

	i = -1;
	philo->forks = malloc((philo->nb_philo) * sizeof(pthread_mutex_t));
	if (!philo->forks)
		free_philo(philo, 1);
	while (++i < philo->nb_philo)
		pthread_mutex_init(&philo->forks[i], NULL);
	pthread_mutex_init(&philo->print, NULL);
	return ;
}

void	threads_init(t_philo *philo)
{
	int				i;
	t_philo_thread	*threads;

	i = -1;
	threads = malloc(philo->nb_philo * sizeof(t_philo_thread));
	if (!threads)
		free_philo(philo, 1);
	philo->philos = malloc((philo->nb_philo) * sizeof(pthread_t));
	if (!philo->philos)
		free_philo(philo, 1);
	while (++i < philo->nb_philo)
	{
		threads[i].philo = philo;
		threads[i].philo_id = i + 1;
		if (pthread_create(&philo->philos[i], NULL, manage_threads,
				&threads[i]) != 0)
			free_philo(philo, 1);
	}
	check_someone_died(philo, threads);
	free_threads(threads, philo, 0);
	return ;
}
