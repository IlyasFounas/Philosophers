/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:11:25 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/20 10:57:44 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(int args)
{
	if (args != 5 && args != 6)
	{
		printf("the program require 4 arguments\n or 5");
		exit(1);
	}
}

void	check_infos(t_philo *philo)
{
	if (philo->nb_philo == LONG_MIN + 1)
		free_philo(philo, 1);
	if (philo->eat_time == LONG_MIN + 1)
		free_philo(philo, 1);
	if (philo->death_time == LONG_MIN + 1)
		free_philo(philo, 1);
	if (philo->sleep_time == LONG_MIN + 1)
		free_philo(philo, 1);
	if (philo->many_times == LONG_MIN + 1)
		free_philo(philo, 1);
}

void	check_someone_died(t_philo *philo, t_philo_thread *threads)
{
	int	i;

	while (philo->death != 1)
	{
		i = -1;
		while (++i < philo->nb_philo)
		{
			pthread_mutex_lock(&threads[i].philo->print);
			time_init_thread(&threads[i]);
			if (threads[i].last_meal == 0)
				threads[i].last_meal = get_absolute_time(threads[i].time.tv_sec
						* 1000 + threads[i].time.tv_usec / 1000,
						threads[i].philo->start);
			if (get_absolute_time(threads[i].last_meal,
					get_absolute_time(threads[i].time.tv_sec * 1000
						+ threads[i].time.tv_usec / 1000,
						threads[i].philo->start)) > threads[i].philo->death_time)
			{
				printf("%ld %ld %ld\n", get_absolute_time(threads[i].last_meal,
						get_absolute_time(threads[i].time.tv_sec * 1000
							+ threads[i].time.tv_usec / 1000,
							threads[i].philo->start)),
					get_absolute_time(threads[i].time.tv_sec * 1000
						+ threads[i].time.tv_usec / 1000,
						threads[i].philo->start), threads[i].last_meal);
				printf("%ld %d died\n", get_absolute_time(threads[i].time.tv_sec
						* 1000 + threads[i].time.tv_usec / 1000,
						threads[i].philo->start), i + 1);
				exit(1);
				// free_threads(threads, philo, 1);
			}
			pthread_mutex_unlock(&threads[i].philo->print);
		}
	}
}
