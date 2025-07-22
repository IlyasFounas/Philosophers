/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:30:40 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/22 16:09:32 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	clean_pids(t_philo *philo)
{
	int	i;

	i = -1;
	if (philo->pids)
	{
		while (++i < philo->nb_philo)
		{
			if (philo->pids[i] > 0)
			{
				kill(philo->pids[i], SIGKILL);
				waitpid(philo->pids[i], NULL, 0);
			}
		}
		free(philo->pids);
	}
}

void	clean_simulation(t_philo *philo)
{
	clean_pids(philo);
	if (philo->forks != SEM_FAILED)
	{
		sem_close(philo->forks);
		sem_unlink("/forks");
	}
	if (philo->write != SEM_FAILED)
	{
		sem_close(philo->write);
		sem_unlink("/write");
	}
	if (philo->dead != SEM_FAILED)
	{
		sem_close(philo->dead);
		sem_unlink("/dead");
	}
	if (philo->meals != SEM_FAILED)
	{
		sem_close(philo->meals);
		sem_unlink("/meals");
	}
	return ;
}

void	init_exit(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
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
	while (s[i])
	{
		if (nb > ((LLONG_MAX - (s[i] - 48)) / 10))
			*error = 1;
		if (-nb < ((LLONG_MIN + (s[i] - 48)) / 10))
			*error = 1;
		nb = (nb * 10) + s[i] - 48;
		i++;
	}
	return (nb * neg);
}
