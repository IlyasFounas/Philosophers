/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:22:22 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/21 11:22:22 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	error_msg(t_philo *philo, char *x_repeat)
{
	int ex;

	ex = 0;
	if (philo->nb_philo < 1)
	{
		write(2, "should have at least 1 philo\n", 29);
		ex = 1;
	}
	if (philo->death_time < 0 || philo->eat_time < 0 || philo->sleep_time < 0)
	{
		write(2, "don't put negatifs numbers\n", 27);
		ex = 1;
	}
	if (x_repeat && philo->x_repeat < 0)
	{
		write(2, "don't put negatifs numbers\n", 27);
		ex = 1;
	}
	if (ex == 1)
		exit(0);
}

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
	philo_process(&philo, philo_threads);
	philo_free_all(&philo, philo_threads);
	return (0);
}

// clear; make ; valgrind --tool=helgrind ./philo 10 500 5 5