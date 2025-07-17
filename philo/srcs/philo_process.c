/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:07:27 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/17 18:33:52 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_check_eat_finished(t_philo_threads *philo_threads)
{
	long	i;

	i = 0;
	pthread_mutex_lock(&philo_threads->philo->eated_mut);
	while (philo_threads[i].eated >= philo_threads[i].intern_x_repeat
		&& i != philo_threads->philo->nb_philo)
		i++;
	pthread_mutex_unlock(&philo_threads->philo->eated_mut);
	if (i == philo_threads->philo->nb_philo)
		return (1);
	return (0);
}

void	*philo_track_death(void *arg)
{
	int				i;
	long			last_eat;
	t_philo_threads	*philo_threads;

	i = 0;
	philo_threads = arg;
	while (42)
	{
		if (philo_check_eat_finished(philo_threads) == 1)
		{
			pthread_mutex_lock(&philo_threads->philo->stdout_acces);
			pthread_mutex_unlock(&philo_threads->philo->stdout_acces);
			exit(0);
		}
		pthread_mutex_lock(&philo_threads[i].philo->last_eat_access[i]);
		last_eat = philo_threads[i].last_eat_time;
		pthread_mutex_unlock(&philo_threads[i].philo->last_eat_access[i]);
		// if (return_actual_time(NULL, &philo_threads[i])
		// 	- last_eat > philo_threads[i].philo->death_time)
		// {
		// 	pthread_mutex_lock(&philo_threads[i].philo->stdout_acces);
		// 	printf("%ld %d died\n", return_actual_time(NULL, &philo_threads[i]),
		// 		philo_threads[i].thread_nb);
		// 	pthread_mutex_unlock(&philo_threads->philo->stdout_acces);
		// 	exit(0);
		// }
		i++;
		if (i >= philo_threads->philo->nb_philo)
			i = 0;
	}
}

void	philo_process(t_philo *philo, t_philo_threads *philo_threads)
{
	int	i;

	i = -1;
	if (philo->nb_philo == 1 || philo->nb_philo == 0)
	{
		ms_sleep(philo, NULL, philo->death_time);
		printf("%ld 1 died", philo->death_time);
		philo_free_all(philo, philo_threads);
	}
	while (++i < philo->nb_philo)
		philo_init_time(NULL, &philo_threads[i]);
	pthread_create(&philo->track_death, NULL, philo_track_death, philo_threads);
	philo_init_threads(philo, philo_threads);
	pthread_join(philo->track_death, NULL);
}
