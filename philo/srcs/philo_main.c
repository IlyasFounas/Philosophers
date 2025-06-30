/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:31:29 by ifounas           #+#    #+#             */
/*   Updated: 2025/06/07 18:31:29 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo philo;
	t_philo_threads *philo_threads;

	philo_threads = NULL;
	if (argc > 6 || argc < 4)
	{
		printf("./philo nb_philo death_time eat_time sleep_time (x_repeat)\n");
		return (0);
	}
	memset(&philo, 0, sizeof(t_philo));
	philo_init(&philo, argv);
	philo_init_tab(&philo, &philo_threads);
	// pthread_create(&philo.track_death, NULL, philo_track_death, philo_threads);
	philo_process(&philo, philo_threads);
	// pthread_join(philo.track_death, NULL);
	return (0);
}

// clear; make ; valgrind --tool=helgrind ./philo 10 500 5 5