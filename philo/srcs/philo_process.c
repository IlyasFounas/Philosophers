/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:07:27 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/07 16:11:52 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_process(t_philo *philo)
{
	if (philo->nb_philo == 1 || philo->nb_philo == 0)
	{
		ms_sleep(philo->death_time / 10);
		printf("philo nb 1 has died");
		philo_free_all(philo);
	}
    philo_init_thread(philo);
}
