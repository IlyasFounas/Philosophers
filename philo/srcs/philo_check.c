/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:11:25 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/07 15:11:57 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    check_args(int args)
{
    if (args != 5 && args != 6)
    {
        printf("the program require 4 arguments\n or 5");
        exit (1);        
    }
}
