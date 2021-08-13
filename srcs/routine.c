/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:40:22 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/13 14:48:50 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <routine.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static void	get_mutex_for_thread(size_t const caller_id,
		size_t const thread_num, size_t *mutex_right, size_t *mutex_left)
{
	*mutex_right = caller_id;
	if (caller_id == 0)
		*mutex_left = thread_num - 1;
	else
		*mutex_left = caller_id - 1;
}

static void	lock_mutex(size_t const caller_id, size_t const thread_num,
		pthread_mutex_t *mutex)
{
	size_t	mutex_right;
	size_t	mutex_left;

	get_mutex_for_thread(caller_id, thread_num, &mutex_right, &mutex_left);
	pthread_mutex_lock(mutex + mutex_right);
	printf("%zu has taken a fork (%zu | %p)\n", caller_id, mutex_right, mutex + mutex_right);
	pthread_mutex_lock(mutex + mutex_left);
	printf("%zu has taken a fork (%zu | %p)\n", caller_id, mutex_left, mutex + mutex_left);
}

static void	unlock_mutex(size_t const caller_id, size_t const thread_num,
		pthread_mutex_t *mutex)
{
	size_t mutex_right;
	size_t mutex_left;

	get_mutex_for_thread(caller_id, thread_num, &mutex_right, &mutex_left);
	pthread_mutex_unlock(mutex + mutex_right);
	pthread_mutex_unlock(mutex + mutex_left);
}

void	*routine(void *arg)
{
	t_routine const	*data = (t_routine *)arg;

	if (data->caller_id % 2 != 0)
		usleep(100);
	while (1)
	{
		lock_mutex(data->caller_id, data->thread_num, data->mutex);
		printf("%zu is eating\n", data->caller_id);
		sleep(2);
		unlock_mutex(data->caller_id, data->thread_num, data->mutex);
		printf("%zu is sleeping\n", data->caller_id);
		sleep(1);
	}
	return (NULL);
}
