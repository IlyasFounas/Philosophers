/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 11:19:25 by ifounas           #+#    #+#             */
/*   Updated: 2025/08/05 11:19:25 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	parsing(char **argv)
{
	str_is_digit(argv[1]);
	str_is_digit(argv[2]);
	str_is_digit(argv[3]);
	str_is_digit(argv[4]);
	if (argv[5])
	{
		str_is_digit(argv[5]);
	}
}

int	main(int argc, char **argv)
{
	t_philo			philo;
	t_philo_threads	*philo_threads;

	philo_threads = NULL;
	if (argc <= 4 || argc > 6)
	{
		printf("./philo nb_philo death_time eat_time sleep_time (nb_meals)\n");
		return (0);
	}
	parsing(argv);
	memset(&philo, 0, sizeof(t_philo));
	memset(&philo.all_mutex, 0, sizeof(t_philo_mut));
	philo_init(&philo, argv);
	philo_init_tab(&philo, &philo_threads);
	philo_process(&philo, philo_threads);
	return (0);
}
