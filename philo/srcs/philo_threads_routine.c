/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads_routine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:23:25 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/07 18:41:45 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *philo_threads_routine(void *arg)
{
    t_philo_threads *philo_threads;

    philo_threads = arg;
    pthread_mutex_lock(&philo_threads->philo->stdout_acces);
    printf("wich = %d\n", philo_threads->thread_nb);
    pthread_mutex_unlock(&philo_threads->philo->stdout_acces);
    return (NULL);
}
