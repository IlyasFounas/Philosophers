/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:44:08 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/07 16:47:44 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void    fill_forks(t_philo *philo)
{
    int i = -1;
    
    philo->forks = malloc((philo->nb_philo) * sizeof(int));
    if (!philo->forks)
        return ;
    while (++i < philo->nb_philo)
        philo->forks[i] = 1;
    return ;
}

void    free_philo(t_philo *philo, int exit_code)
{
    if (philo->forks)
        free(philo->forks);
    exit(exit_code);
}

int main(int arc, char **arv)
{
    t_philo philo;
    struct timeval time;
    time_t n;
    
    check_args(arc);
    memset(&philo, 0, sizeof(t_philo));
    philo.nb_philo = ft_atoi_error(arv[1]);
    if (ft_atoi_error(arv[1]) == LONG_MIN + 1)
        free_philo(&philo, 1);
    fill_forks(&philo);
    if (gettimeofday(&time, NULL) == -1)
        free_philo(&philo, 1);
    printf("%ld \n", time.tv_usec);
    free_philo(&philo, 0);
}
