/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:07:27 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/07 18:44:06 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void philo_track_death(void)
{
	return ;
}

void	philo_process(t_philo *philo, t_philo_threads *philo_threads)
{
	if (philo->nb_philo == 1 || philo->nb_philo == 0)
	{
		ms_sleep(philo->death_time / 10);
		printf("philo nb 1 has died");
		philo_free_all(philo, philo_threads);
	}
    philo_init_threads(philo, philo_threads);
	philo_track_death();
}
