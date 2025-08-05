/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:46:57 by ifounas           #+#    #+#             */
/*   Updated: 2025/08/04 16:46:57 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init_tab(t_philo *philo, t_philo_threads **philo_threads)
{
	int	i;

	i = -1;
	*philo_threads = malloc((philo->nb_philo) * sizeof(t_philo_threads));
	if (!*philo_threads)
		philo_free_all(philo, NULL);
	while (++i < philo->nb_philo)
	{
		(*philo_threads)[i].philo = philo;
		(*philo_threads)[i].thread_nb = i + 1;
		(*philo_threads)[i].meals = 0;
		(*philo_threads)[i].last_eat_time = return_actual_time(philo, NULL);
		if (pthread_mutex_init(&(*philo_threads)[i].meals_mut, NULL) == -1)
			philo_free_all(philo, NULL);
	}
}

void	philo_init_threads(t_philo *philo, t_philo_threads *philo_threads)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	pthread_mutex_lock(&philo->all_mutex.start_simulation_mut);
	while (++i < philo->nb_philo)
	{
		if (pthread_create(&philo->philos[i], NULL, philo_threads_routine,
				&philo_threads[i]) != 0)
		{
			while (--i >= 0)
				pthread_join(philo->philos[i], NULL);
			pthread_mutex_unlock(&philo->all_mutex.start_simulation_mut);
			philo_free_all(philo, philo_threads);
		}
	}
	i = -1;
	while (++i < philo->nb_philo)
		philo_init_time(NULL, &philo_threads[i]);
	pthread_mutex_unlock(&philo->all_mutex.start_simulation_mut);
	philo_monitor(philo_threads);
	while (++j < philo->nb_philo)
		pthread_join(philo->philos[j], NULL);
}

void	philo_init_forks(t_philo *philo)
{
	int	i;

	i = -1;
	philo->forks_tab = malloc(philo->nb_philo * sizeof(int));
	if (!philo->forks_tab)
		philo_free_all(philo, NULL);
	while (++i < philo->nb_philo)
		philo->forks_tab[i] = 1;
	return ;
}

void	str_is_digit(char *str)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[y])
		y++;
	if (i != y)
	{
		write(2, "only digits are allowed\n", 24);
		exit(1);
	}
}

void	philo_init(t_philo *philo, char **argv)
{
	int	error;

	error = 0;
	philo_init_time(philo, NULL);
	philo->nb_philo = ft_atoi_ult(argv[1], &error);
	philo->death_time = ft_atoi_ult(argv[2], &error);
	philo->eat_time = ft_atoi_ult(argv[3], &error);
	philo->sleep_time = ft_atoi_ult(argv[4], &error);
	if (argv[5])
	{
		philo->x_repeat = ft_atoi_ult(argv[5], &error);
	}
	else
		philo->x_repeat = -1;
	if (error == 1)
	{
		write(2, "int overflow\n", 13);
		exit(1);
	}
	error_msg(philo, argv[5]);
	philo_init_mutex(philo, -1);
	philo_init_forks(philo);
	philo->philos = malloc((philo->nb_philo) * sizeof(pthread_t));
	if (!philo->philos)
		philo_free_all(philo, NULL);
}
