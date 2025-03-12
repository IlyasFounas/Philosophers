/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:42:12 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/12 15:40:58 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	is_someone_dead(long int eaten, t_philo_thread *thread)
{
	int	i;

	i = 1;
	time_init(thread->philo);
	if (eaten - get_absulte_time(thread->philo->time.tv_usec,
			thread->philo->start) / 1000 < 0)
		i = -1;
	if ((eaten - (get_absulte_time(thread->philo->time.tv_usec,
					thread->philo->start) / 1000)
			* i) > thread->philo->death_time)
	{
		printf("%ld %d died\n", get_absulte_time(thread->philo->time.tv_usec,
				thread->philo->start) / 1000, thread->philo_id);
		free_threads(thread->philo, 1);
	}
}

static void	eat_time(t_philo_thread *thread, int i)
{
	int	y;

	if (i == thread->philo->nb_philo)
		y = 0;
	else
		y = i;
	time_init(thread->philo);
	printf("%ld %d has taken a fork\n",
		get_absulte_time(thread->philo->time.tv_usec, thread->philo->start)
		/ 1000, i);
	pthread_mutex_lock(&thread->philo->forks[i - 1]);
	time_init(thread->philo);
	printf("%ld %d has taken a fork\n",
		get_absulte_time(thread->philo->time.tv_usec, thread->philo->start)
		/ 1000, i);
	pthread_mutex_lock(&thread->philo->forks[y]);
	time_init(thread->philo);
	printf("%ld %d is eating\n", get_absulte_time(thread->philo->time.tv_usec,
			thread->philo->start) / 1000, i);
	usleep(thread->philo->eat_time * 1000);
	time_init(thread->philo);
	pthread_mutex_unlock(&thread->philo->forks[i - 1]);
	pthread_mutex_unlock(&thread->philo->forks[y]);
}

static void	wait_manage(t_philo_thread *thread, int i, char *str, long int time)
{
	time_init(thread->philo);
	printf("%ld %d %s\n", get_absulte_time(thread->philo->time.tv_usec,
			thread->philo->start) / 1000, i, str);
	usleep(time * 1000);
}

void	*manage_threads(void *arg)
{
	int				inner_while;
	int				i;
	long int		eaten;
	t_philo_thread	*thread;

	inner_while = 0;
	thread = (t_philo_thread *)arg;
	i = thread->philo_id;
	time_init(thread->philo);
	while (thread->philo->death != 1)
	{
		eat_time(thread, i);
		time_init(thread->philo);
		eaten = get_absulte_time(thread->philo->time.tv_usec,
				thread->philo->start) / 1000;
		wait_manage(thread, i, "is sleeping", thread->philo->sleep_time);
		is_someone_dead(eaten, thread);
		wait_manage(thread, i, "is thinking", thread->philo->think_time);
		is_someone_dead(eaten, thread);
		inner_while++;
		if (inner_while == 1)
			return (NULL);
	}
	return (NULL);
}
