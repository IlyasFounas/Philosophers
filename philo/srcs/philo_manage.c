/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifounas <ifounas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:42:12 by ifounas           #+#    #+#             */
/*   Updated: 2025/03/17 14:05:48 by ifounas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	is_someone_dead(t_philo_thread *thread)
// {
// 	long int	actual_time;

// 	time_init(thread->philo);
// 	actual_time = get_absolute_time(thread->philo->time.tv_usec,
// 			thread->philo->start) / 1000;
// 	if (get_absolute_time(thread->last_meal,
// 			actual_time) > thread->philo->death_time)
// 	{
// 		pthread_mutex_unlock(&thread->philo->forks[thread->philo_id - 1]);
// 		printf("%ld %d died\n", actual_time, thread->philo_id);
// 		thread->died = 1;
// 	}
// 	thread->died = 0;
// }

static void	take_a_fork(t_philo_thread *thread, int i)
{
	pthread_mutex_lock(&thread->philo->forks[i]);
	// is_someone_dead(thread);
	if (thread->died == 1)
		return ;
	time_init(thread->philo);
	printf("%ld %d has taken a fork %d\n",
		get_absolute_time(thread->philo->time.tv_usec, thread->philo->start)
		/ 1000, thread->philo_id, i);
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
		if (thread->died == 1)
			return ;
		take_a_fork(thread, y);
	}
	else
	{
		take_a_fork(thread, y);
		if (thread->died == 1)
			return ;
		take_a_fork(thread, i - 1);
	}
	if (thread->died == 1)
		return ;
	time_init(thread->philo);
	printf("%ld %d is eating\n", get_absolute_time(thread->philo->time.tv_usec,
			thread->philo->start) / 1000, i);
	usleep(thread->philo->eat_time * 1000);
	pthread_mutex_unlock(&thread->philo->forks[i - 1]);
	pthread_mutex_unlock(&thread->philo->forks[y]);
}

static void	wait_manage(t_philo_thread *thread, int i, char *str, long int time)
{
	// is_someone_dead(thread);
	// if (thread->died == 1)
	// 	return ;
	time_init(thread->philo);
	
	printf("%ld %d %s\n", get_absolute_time(thread->philo->time.tv_usec,
			thread->philo->start) / 1000, i, str);
	usleep(time * 1000);
	// is_someone_dead(thread);
	// if (thread->died == 1)
	// 	return ;
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
		// if (thread->died == 1)
		// 	return (thread->philo->death = 1, NULL);
		time_init(thread->philo);
		thread->last_meal = 1;
		// thread->last_meal = get_absolute_time(thread->philo->time.tv_usec,
		// 		thread->philo->start) / 1000;
		wait_manage(thread, thread->philo_id, "is sleeping",
			thread->philo->sleep_time);
		// if (thread->died == 1)
		// 	return (thread->philo->death = 1, NULL);
		wait_manage(thread, thread->philo_id, "is thinking",
			thread->philo->think_time);
		if (inner_while == 1)
			return (thread->philo->death = 1, NULL);
		else if (inner_while != 0)
			inner_while--;
	}
	return (NULL);
}
