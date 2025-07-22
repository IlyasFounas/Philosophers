/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:24:25 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/22 17:04:23 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eating(t_philo *philo, int philo_nb)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		sem_wait(philo->forks);
		sem_wait(philo->write);
		printf("%ld %d has taken a fork\n", return_actual_time(philo),
			philo_nb);
		sem_post(philo->write);
	}
	sem_wait(philo->write);
	printf("%ld %d is eating\n", return_actual_time(philo), philo_nb);
	sem_post(philo->write);
	ms_sleep(philo, philo->eat_time);
	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	philo_sleep_think(t_philo *philo, int philo_nb)
{
	sem_wait(philo->write);
	printf("%ld %d is sleeping\n", return_actual_time(philo), philo_nb);
	sem_post(philo->write);
	ms_sleep(philo, philo->sleep_time);
	sem_wait(philo->write);
	printf("%ld %d is thinking\n", return_actual_time(philo), philo_nb);
	sem_post(philo->write);
}

void	routine_bonus(t_philo *philo, int philo_nb)
{
	int	meals;

	meals = 0;
	while (42)
	{
		philo_eating(philo, philo_nb);
		meals++;
		if (meals >= philo->x_repeat)
			sem_post(philo->meals);
		philo_sleep_think(philo, philo_nb);
	}
	return ;
}
