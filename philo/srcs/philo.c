/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:44:08 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/08 16:18:22 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int arc, char **arv)
{
	t_philo			philo;

	check_args(arc);
	memset(&philo, 0, sizeof(t_philo));
	philo.nb_philo = ft_atoi_error(arv[1]);
	philo.death_time = ft_atoi_error(arv[2]);
	philo.eat_time = ft_atoi_error(arv[3]);
	philo.sleep_time = ft_atoi_error(arv[4]);
	if (ft_atoi_error(arv[1]) == LONG_MIN + 1)
		free_philo(&philo, 1);
	if (gettimeofday(&philo.time, NULL) == -1)
		free_philo(&philo, 1);
	forks_init(&philo);
    threads_init(&philo);
	free_philo(&philo, 0);
}
