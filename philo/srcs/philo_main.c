/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:33:49 by marvin            #+#    #+#             */
/*   Updated: 2025/06/07 00:14:55 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void	ft_usleep(int x_time)
{
	int	i;

	i = -1;
	while (++i < x_time)
		usleep(100);
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
	printf("%ld %ld \n", philo.nb_philo, philo.death_time);
	return (0);
}
