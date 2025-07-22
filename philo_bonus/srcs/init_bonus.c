/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:31:29 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/22 17:02:55 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long int	return_actual_time(t_philo *philo)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		clean_simulation(philo);
		exit(1);
	}
	if (philo)
		return (((time.tv_sec * 1000) + (time.tv_usec / 1000))
			- philo->start_time);
	return (0);
}

void	philo_init_time(t_philo *philo)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		clean_simulation(philo);
		exit(1);
	}
	if (philo)
		philo->start_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return ;
}

void	ms_sleep(t_philo *philo, int x_time)
{
	long int	start;

	start = return_actual_time(philo);
	while (return_actual_time(philo) - start < x_time)
		usleep(100);
	return ;
}

static void	init_semaphores(t_philo *philo)
{
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/dead");
	sem_unlink("/meals");
	philo->forks = sem_open("/forks", O_CREAT, 0644, philo->nb_philo);
	philo->dead = sem_open("/dead", O_CREAT, 0644, 0);
	philo->write = sem_open("/write", O_CREAT, 0644, 1);
	philo->meals = sem_open("/meals", O_CREAT, 0644, 0);
	if (philo->dead == SEM_FAILED || philo->write == SEM_FAILED
		|| philo->forks == SEM_FAILED || philo->meals == SEM_FAILED)
	{
		clean_simulation(philo);
		exit(1);
	}
	return ;
}

void	init_bonus(t_philo *philo, char **argv)
{
	int	error;

	philo->nb_philo = ft_atoi_ult(argv[1], &error);
	if (error == 1)
		init_exit("philo_bonus : error numbers philos\n");
	philo->death_time = ft_atoi_ult(argv[2], &error);
	if (error == 1)
		init_exit("philo_bonus : error time to die\n");
	philo->eat_time = ft_atoi_ult(argv[3], &error);
	if (error == 1)
		init_exit("philo_bonus : error time to eat\n");
	philo->sleep_time = ft_atoi_ult(argv[4], &error);
	if (error == 1)
		init_exit("philo_bonus : error time to sleep\n");
	if (argv[5])
	{
		philo->x_repeat = ft_atoi_ult(argv[5], &error);
		if (error == 1)
			init_exit("philo_bonus : error number meals\n");
	}
	else
		philo->x_repeat = -1;
	init_semaphores(philo);
}
