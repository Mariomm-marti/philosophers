/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:40:22 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/12 20:13:05 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <routine.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

static void	get_mutex_for_thread(size_t const caller_id,
		size_t const thread_num)
{
}

static void	lock_me(size_t const caller_id, size_t const thread_num,
		pthread_mutex_t *mutex)
{
	size_t	mutex_one;
	size_t	mutex_two;


	pthread_mutex_lock(mutex + caller_id);
}

void	*routine(void *arg)
{
	t_routine const	*data = (t_routine *)arg;

	while (1)
	{
		lock_me(data->caller_id, data->thread_num, data->mutex, pthread_mutex_lock, "%d has taken fork (%d)\n");
		usleep(40000);
		lock_me(data->caller_id, data->thread_num, data->mutex, pthread_mutex_unlock, "%d has left the fork (%d)\n");
	}
	return (NULL);
}
