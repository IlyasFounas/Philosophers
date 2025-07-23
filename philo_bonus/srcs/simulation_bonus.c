/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:44:04 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/23 10:02:03 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	free_pids(t_philo *philo, int i)
{
	while (--i >= 0)
	{
		kill(philo->pids[i], SIGKILL);
		waitpid(philo->pids[i], NULL, 0);
	}
}

static void	track_death(t_philo *philo)
{
	sem_wait(philo->write);
	// printf("%ld %d died\n", return_actual_time(philo), philo_nb);
	sem_post(philo->write);
	free_pids(philo, philo->nb_philo);
	sem_post(philo->dead);
}

static void	*monitor_check(void *arg)
{
	t_philo		*philo;
	long int	all_meals;

	philo = arg;
	all_meals = 0;
	while (42)
	{
		if (philo->x_repeat > -1)
		{
			sem_wait(philo->meals);
			all_meals++;
			if (all_meals >= philo->x_repeat)
			{
				free_pids(philo, philo->nb_philo);
				sem_post(philo->dead);
				break ;
			}
		}
		sem_wait(philo->dead);
		track_death(philo);
		break ;
	}
	return (NULL);
}

void	launch_simulation(t_philo *philo)
{
	int	i;

	i = -1;
	philo_init_time(philo);
	pthread_create(&philo->monitor, NULL, monitor_check, philo);
	while (++i < philo->nb_philo)
	{
		philo->pids[i] = fork();
		if (philo->pids[i] == 0)
			routine_bonus(philo, i + 1);
		else if (philo->pids[i] == -1)
		{
			write(2, "philo_bonus : fork failed\n", 26);
			free_pids(philo, i);
			break ;
		}
	}
	pthread_join(philo->monitor, NULL);
}
