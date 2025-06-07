/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 23:58:14 by marvin            #+#    #+#             */
/*   Updated: 2025/06/07 00:15:14 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "philo.h"

long int	ft_atoi_ult(char *s, int *error)
{
	int i;
	long int nb;
    int neg;

	i = 0;
	nb = 0;
    neg = 1;
    while ((s[i] >= 9 && s[i] <= 13) || (s[i] == ' '))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = -1;
		i++;
	}
	while (s[i])
	{
		if (nb > ((LLONG_MAX - (s[i] - 48)) / 10))
			*error = 1;
		if (-nb < ((LLONG_MIN + (s[i] - 48)) / 10))
			*error = 1; 
		nb = (nb * 10) + s[i] - 48;
        i++;
	}
	return (nb * neg);
}
