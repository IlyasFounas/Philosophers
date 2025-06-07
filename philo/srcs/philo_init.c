/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 00:06:59 by marvin            #+#    #+#             */
/*   Updated: 2025/06/07 00:11:48 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

void philo_init(t_philo *philo, char **argv)
{
    int error;

    error = 0;
    philo->nb_philo = ft_atoi_ult(argv[1], &error);
    philo->death_time = ft_atoi_ult(argv[2], &error);
    philo->eat_time = ft_atoi_ult(argv[3], &error);
    philo->sleep_time = ft_atoi_ult(argv[4], &error);
    if (argv[5])
        philo->x_repeat = ft_atoi_ult(argv[5], &error);
    if (error == 1)
    {
        printf("long int overflow\n");
        exit(0);
    }
}
