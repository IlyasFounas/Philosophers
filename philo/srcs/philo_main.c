/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 16:05:30 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/07 16:05:30 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ms_sleep(int x_time)
{
	int	i;

	i = -1;
	while (++i < x_time)
		usleep(1000);
	return ;
}

int	main(int argc, char **argv)
{
	t_philo philo;

	memset(&philo, 0, sizeof(t_philo));
	if (argc > 6 || argc < 4)
	{
		printf("./philo nb_philo death_time eat_time sleep_time (x_repeat)\n");
		return (0);
	}
	philo_init(&philo, argv);
	philo_process(philo);
	return (0);
}
