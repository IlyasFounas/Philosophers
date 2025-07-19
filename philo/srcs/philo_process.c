/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:07:27 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/19 17:59:01 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_check_eat_finished(t_philo_threads *philo_threads)
{
	int			i;
	long int	j;

	i = -1;
	j = 0;
	while (++i < philo_threads->philo->nb_philo)
	{
		pthread_mutex_lock(&philo_threads[i].meals_mut);
		if (philo_threads[i].meals >= philo_threads->philo->x_repeat)
			j++;
		pthread_mutex_unlock(&philo_threads[i].meals_mut);
	}
	if (j >= philo_threads->philo->nb_philo - 1)
		return (1);
	return (0);
}

void	*philo_track_death(void *arg)
{
	int				i;
	int				y;
	t_philo_threads	*philo_threads;

	i = 0;
	y = 0;
	philo_threads = arg;
	while (42)
	{
		if (philo_threads->philo->x_repeat != -1
			&& philo_check_eat_finished(philo_threads) == 1)
		{
			pthread_mutex_lock(&philo_threads->philo->stop_simulation_mut);
			philo_threads->philo->stop_simualtion = 1;
			pthread_mutex_unlock(&philo_threads->philo->stop_simulation_mut);
			return (NULL);
		}
		i++;
		if (i >= philo_threads->philo->nb_philo)
			i = 0;
		usleep(10000);
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

// pthread_mutex_lock(&philo_threads[i].philo->last_eat_access[i]);
// last_eat = philo_threads[i].last_eat_time;
// pthread_mutex_unlock(&philo_threads[i].philo->last_eat_access[i]);
// if (return_actual_time(NULL, &philo_threads[i])
// 	- last_eat > philo_threads[i].philo->death_time)
// {
// 	pthread_mutex_lock(&philo_threads[i].philo->stdout_acces);
// 	printf("%ld %d died\n", return_actual_time(NULL, &philo_threads[i]),
// 		philo_threads[i].thread_nb);
// 	pthread_mutex_unlock(&philo_threads->philo->stdout_acces);
// 	exit(0);
// }