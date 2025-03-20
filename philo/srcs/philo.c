/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:44:08 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/20 11:19:17 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	get_absolute_time(long int t1, long int t2)
{
	if (t1 - t2 < 0)
		return ((t1 - t2) * -1);
	return (t1 - t2);
}

int	main(int arc, char **arv)
{
	t_philo	philo;

	check_args(arc);
	memset(&philo, 0, sizeof(t_philo));
	philo_init(&philo, ft_atoi_error(arv[1]), ft_atoi_error(arv[2]),
		ft_atoi_error(arv[3]));
	philo.sleep_time = ft_atoi_error(arv[4]);
	// philo.think_time = get_absolute_time(philo.death_time, (philo.eat_time
	// 			+ philo.sleep_time));
	philo.think_time = 0;
	if (arc == 6)
		philo.many_times = ft_atoi_error(arv[5]);
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
