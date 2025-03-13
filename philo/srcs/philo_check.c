/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:11:25 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/13 13:25:45 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_args(int args)
{
	if (args != 5 && args != 6)
	{
		printf("the program require 4 arguments\n or 5");
		exit(1);
	}
}

void	check_infos(t_philo *philo)
{
	if (philo->nb_philo == LONG_MIN + 1)
		free_philo(philo, 1);
	if (philo->eat_time == LONG_MIN + 1)
		free_philo(philo, 1);
	if (philo->death_time == LONG_MIN + 1)
		free_philo(philo, 1);
	if (philo->sleep_time == LONG_MIN + 1)
		free_philo(philo, 1);
	if (philo->many_times == LONG_MIN + 1)
		free_philo(philo, 1);
}
