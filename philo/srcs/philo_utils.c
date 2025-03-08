/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 14:03:01 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/08 14:29:39 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

static int	ft_isdigit_philo(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	is_or_isnt_negatif(char c, int *neg, int i)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			*neg = -1;
		i++;
	}
	return (i);
}

static int	ft_verif(const char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (ft_isdigit_philo(s[i]) != 1 && s[i] != '+' && s[i] != '-')
			return (0);
	return (1);
}

long int	ft_atoi_error(const char *nptr)
{
	int			i;
	int			neg;
	long int	nb;
	int			temp;

	nb = 0;
	neg = 1;
	i = 0;
	temp = 0;
	if (ft_verif(nptr) == 0)
		return (LONG_MIN + 1);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	i = is_or_isnt_negatif(nptr[i], &neg, i);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = (nb * 10) + (nptr[i++] - 48);
		if (nb * neg != (int)(nb * neg))
			return (LONG_MIN + 1);
		if (!temp)
			temp++;
	}
	if (!temp || (nptr[i] != '\0'))
		return (LONG_MIN + 1);
	return (nb * neg);
}
