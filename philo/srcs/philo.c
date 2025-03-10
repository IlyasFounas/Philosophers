/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:44:08 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/10 13:02:51 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int arc, char **arv)
{
	t_philo		philo;
	suseconds_t	start;

	check_args(arc);
	memset(&philo, 0, sizeof(t_philo));
	if (gettimeofday(&philo.time, NULL) == -1)
		free_philo(&philo, 1);
	start = philo.time.tv_usec;
	philo.nb_philo = ft_atoi_error(arv[1]);
	philo.death_time = ft_atoi_error(arv[2]);
	philo.eat_time = ft_atoi_error(arv[3]);
	philo.sleep_time = ft_atoi_error(arv[4]);
	check_infos(&philo);
	forks_init(&philo);
	threads_init(&philo);
	free_philo(&philo, 0);
}
