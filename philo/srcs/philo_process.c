/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:07:27 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/18 14:02:31 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

static void philo_track_death(void)
{
	return ;
}

void	philo_process(t_philo *philo, t_philo_threads *philo_threads)
{
	if (philo->nb_philo == 1 || philo->nb_philo == 0)
	{
		ms_sleep(philo, NULL,philo->death_time);
		printf("philo nb 1 has died");
		philo_free_all(philo, philo_threads);
	}
	printf("global start_time = %ld\n", philo->start_time);
    philo_init_threads(philo, philo_threads);
	philo_track_death();
}
