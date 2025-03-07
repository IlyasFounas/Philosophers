/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:45:33 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/07 15:12:13 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_philo
{
	int		nb_philo;
	int		death;
	int		*forks;
}			t_philo;

// philo check
void		check_args(int args);

// philo_utils
long int	ft_atoi_error(const char *nptr);

#endif