/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:44:08 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/12 15:45:37 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int arc, char **arv)
{
	t_philo		philo;

	check_args(arc);
	memset(&philo, 0, sizeof(t_philo));
	time_init(&philo);
	philo.start =  philo.time.tv_usec;
	philo.nb_philo = ft_atoi_error(arv[1]);
	philo.death_time = ft_atoi_error(arv[2]);
	philo.eat_time = ft_atoi_error(arv[3]);
	philo.sleep_time = ft_atoi_error(arv[4]);
	philo.think_time = philo.death_time - (philo.eat_time + philo.sleep_time);
	if (philo.think_time < 0)
		philo.think_time *= -1;
	check_infos(&philo);
	forks_init(&philo);
	if (philo.nb_philo == 0)
		free_philo(&philo, 1);
	if (philo.nb_philo == 1)
	{
		usleep(philo.death_time * 1000);
		printf("%ld 1 died\n", philo.death_time);
		free_philo(&philo, 0);
	}
	threads_init(&philo);
}
