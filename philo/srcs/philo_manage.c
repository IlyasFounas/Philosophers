/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:42:12 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/11 14:52:30 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*manage_threads(void *arg)
{
	int				inner_while;
	int				y;
	int				i;
	t_philo_thread	*thread;
	long int		start;
	long int		now;

	thread = (t_philo_thread *)arg;
	inner_while = 0;
	while (thread->philo->death != 1)
	{
		i = thread->philo_id;
		time_init(thread->philo);
		start = thread->philo->time.tv_usec * 1000;
		if (i == thread->philo->nb_philo)
			y = 0;
		else
			y = i;
		pthread_mutex_lock(&thread->philo->forks[i - 1]);
		pthread_mutex_lock(&thread->philo->forks[y]);
		printf("%ld %d is eating\n", start - thread->philo->start, i);
		usleep(thread->philo->eat_time * 1000);
		time_init(thread->philo);
		now = thread->philo->time.tv_usec * 1000;
		pthread_mutex_unlock(&thread->philo->forks[i - 1]);
		pthread_mutex_unlock(&thread->philo->forks[y]);
        inner_while++;
        if (inner_while == 5)
            return (NULL);
    }
    return (NULL);
}

// 1 : parsing
// 2 : gestion des threads
// 3 : gestion du temps
// 4 : gestion des actions avec des mutex
// 5 : leaks