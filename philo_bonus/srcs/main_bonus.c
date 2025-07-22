/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 10:27:01 by ifounas           #+#    #+#             */
/*   Updated: 2025/07/22 17:44:31 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc > 6 || argc < 4)
	{
		printf("./philo_bonus nb_philo death_time eat_time sleep_time (nb_meals)\n");
		return (0);
	}
	memset(&philo, 0, sizeof(t_philo));
	init_bonus(&philo, argv);
	philo.pids = malloc((philo.nb_philo) * sizeof(pid_t));
	if (philo.pids)
		launch_simulation(&philo);
	else
		write(2, "philo_bonus : malloc error\n", 27);
	sem_wait(philo.dead);
	clean_simulation(&philo);
	return (0);
}
