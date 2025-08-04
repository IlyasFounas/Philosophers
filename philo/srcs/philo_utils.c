/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:57:59 by ifounas           #+#    #+#             */
/*   Updated: 2025/08/04 16:57:59 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_simple_mutex(t_philo *philo)
{
	if (pthread_mutex_init(&philo->all_mutex.stdout_acces, NULL) == -1)
	{
		philo->all_mutex.stdout_mut_failed = 1;
		philo_free_all(philo, NULL);
	}
	if (pthread_mutex_init(&philo->all_mutex.dead_philo_mut, NULL) == -1)
	{
		philo->all_mutex.dead_mut_failed = 1;
		philo_free_all(philo, NULL);
	}
	if (pthread_mutex_init(&philo->all_mutex.stop_simulation_mut, NULL) == -1)
	{
		philo->all_mutex.simulation_mut_failed = 1;
		philo_free_all(philo, NULL);
	}
	if (pthread_mutex_init(&philo->all_mutex.start_simulation_mut, NULL) == -1)
	{
		philo->all_mutex.start_mut_failed = 1;
		philo_free_all(philo, NULL);
	}
	if (pthread_mutex_init(&philo->all_mutex.threads_mut, NULL) == -1)
	{
		philo->all_mutex.threads_mut_failed = 1;
		philo_free_all(philo, NULL);
	}
}

void	mutex_init_failed(t_philo *philo, int i, int first)
{
	write(2, "init mutex failed\n", 18);
	philo->exit_option = 1;
	if (first == 0)
		pthread_mutex_destroy(&philo->all_mutex.forks[i]);
	while (--i >= 0)
	{
		pthread_mutex_destroy(&philo->all_mutex.forks[i]);
		pthread_mutex_destroy(&philo->all_mutex.last_eat_access[i]);
	}
	free(philo->all_mutex.forks);
	free(philo->all_mutex.last_eat_access);
	philo->all_mutex.forks = NULL;
	philo->all_mutex.last_eat_access = NULL;
	philo_free_all(philo, NULL);
}

void	philo_init_mutex(t_philo *philo, int i)
{
	philo_simple_mutex(philo);
	philo->all_mutex.forks = malloc(philo->nb_philo * sizeof(pthread_mutex_t));
	if (!philo->all_mutex.forks)
		philo_free_all(philo, NULL);
	philo->all_mutex.last_eat_access = malloc(philo->nb_philo
			* sizeof(pthread_mutex_t));
	if (!philo->all_mutex.last_eat_access)
		philo_free_all(philo, NULL);
	while (++i < philo->nb_philo)
	{
		if (pthread_mutex_init(&philo->all_mutex.forks[i], NULL) == -1)
			mutex_init_failed(philo, i, 1);
		if (pthread_mutex_init(&philo
				->all_mutex.last_eat_access[i], NULL) == -1)
			mutex_init_failed(philo, i, 0);
	}
}

void	set_forks(t_philo_threads *philo_threads)
{
	int	tmp;

	philo_threads->fork1 = philo_threads->thread_nb - 1;
	philo_threads->fork2 = philo_threads->thread_nb
		% philo_threads->philo->nb_philo;
	if (philo_threads->thread_nb % 2 != 0)
	{
		tmp = philo_threads->fork1;
		philo_threads->fork1 = philo_threads->fork2;
		philo_threads->fork2 = tmp;
	}
}

long int	ft_atoi_ult(char *s, int *error)
{
	int			i;
	long int	nb;
	int			neg;

	i = 0;
	nb = 0;
	neg = 1;
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == ' '))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		if (nb > ((INT_MAX - (s[i] - 48)) / 10))
			*error = 1;
		if (-nb < ((INT_MIN + (s[i] - 48)) / 10))
			*error = 1;
		nb = (nb * 10) + s[i] - 48;
		i++;
	}
	return (nb * neg);
}
