/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:11:25 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/18 13:44:55 by ifounas          ###   ########.fr       */
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
		time_init(philo);
		i = -1;
		while (++i < philo->nb_philo)
		{
			if (get_absolute_time(threads[i].last_meal,
					get_absolute_time(threads[i].philo->time.tv_usec, 0))
				/ 1000 > philo->death_time)
			{
				printf("%ld %d died\n", philo->time.tv_usec / 1000, i + 1);
				return ;
				// exit(1);
				// free_threads(threads, philo, 1);
			}
		}
	}
}
