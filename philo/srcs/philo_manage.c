/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:42:12 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/10 17:06:52 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*manage_threads(void *arg)
{
	static int	i = 0;
	t_philo *philo = (t_philo *)arg;

    pthread_mutex_lock(&philo->forks[i]);
	i++;
	printf("philo %d have eaten\n", i);
    if (i > 0) {
        pthread_mutex_unlock(&philo->forks[i - 1]);
    }
    else if (i == 0)
        pthread_mutex_unlock(&philo->forks[0]);
    return (NULL);
}


// 1 : parsing
// 2 : gestion des threads
// 3 : gestion du temps
// 4 : gestion des actions avec des mutex
// 5 : leaks