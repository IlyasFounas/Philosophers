/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:43:33 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/10 16:31:23 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo *philo, int exit_code)
{
	free(philo->philos);
	philo->philos = NULL;
	pthread_mutex_destroy(philo->forks);
	free(philo->forks);
	exit(exit_code);
}
