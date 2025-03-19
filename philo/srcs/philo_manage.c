/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:42:12 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/19 13:25:26 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_a_fork(t_philo_thread *thread, int i)
{
	pthread_mutex_lock(&thread->philo->forks[i]);
	time_init_thread(thread);
	printf("%ld %d has taken a fork\n", get_absolute_time(thread->time.tv_sec
			* 1000 + thread->time.tv_usec / 1000, thread->philo->start),
		thread->philo_id);
}

static void	eat_time(t_philo_thread *thread, int i)
{
	int	y;

	y = i;
	if (i == thread->philo->nb_philo)
		y = 0;
	if (thread->philo_id % 2 != 0)
	{
		take_a_fork(thread, i - 1);
		take_a_fork(thread, y);
	}
	else
	{
		take_a_fork(thread, y);
		take_a_fork(thread, i - 1);
	}
	pthread_mutex_lock(&thread->philo->print);
	time_init_thread(thread);
	printf("%ld %d is eating\n", get_absolute_time(thread->time.tv_sec * 1000
			+ thread->time.tv_usec / 1000, thread->philo->start), i);
	pthread_mutex_unlock(&thread->philo->print);
	usleep(thread->philo->eat_time * 1000);
	pthread_mutex_unlock(&thread->philo->forks[i - 1]);
	pthread_mutex_unlock(&thread->philo->forks[y]);
}

static void	wait_manage(t_philo_thread *thread, int i, char *str, long int time)
{
	pthread_mutex_lock(&thread->philo->print);
	time_init_thread(thread);
	printf("%ld %d %s\n", get_absolute_time(thread->time.tv_sec * 1000
			+ thread->time.tv_usec / 1000, thread->philo->start), i, str);
	pthread_mutex_unlock(&thread->philo->print);
	usleep(time * 1000);
}

void	*manage_threads(void *arg)
{
	t_philo_thread	*thread;
	int				inner_while;

	thread = (t_philo_thread *)arg;
	inner_while = (int)thread->philo->many_times;
	thread->last_meal = 0;
	while (thread->philo->death != 1)
	{
		eat_time(thread, thread->philo_id);
		time_init_thread(thread);
		thread->last_meal = get_absolute_time(thread->time.tv_sec * 1000
				+ thread->time.tv_usec / 1000, thread->philo->start);
		wait_manage(thread, thread->philo_id, "is sleeping",
			thread->philo->sleep_time);
		wait_manage(thread, thread->philo_id, "is thinking",
			thread->philo->think_time);
		if (inner_while == 1)
			return (thread->philo->death = 1, NULL);
		else if (inner_while != 0)
			inner_while--;
	}
	return (NULL);
}
