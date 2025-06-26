/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:05:38 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/18 14:01:21 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void set_forks(t_philo_threads *philo_threads)
{
	int	fork1;
	int	fork2;
	int	tmp;

	fork1 = philo_threads->thread_nb - 1;
	fork2 = philo_threads->thread_nb % philo_threads->philo->nb_philo;
	if (fork1 > fork2)
	{
		tmp = fork1;
		fork1 = fork2;
		fork2 = tmp;
	}
	philo_threads->fork1 = fork1;
	philo_threads->fork2 = fork2;
}

long int	ft_atoi_ult(char *s, int *error)
{
	int i;
	long int nb;
    int neg;

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
