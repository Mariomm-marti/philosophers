/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_lock_mutex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:58:18 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/13 18:08:31 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <pthread.h>
#include <common.h>

static void	get_mutex_for_thread(size_t const caller_id,
			size_t const thread_num, size_t *mutex_right, size_t *mutex_left)
{
	*mutex_right = caller_id;
	if (caller_id == 0)
		*mutex_left = thread_num - 1;
	else
		*mutex_left = caller_id - 1;
}

void	lock_mutex(size_t const caller_id, size_t const thread_num,
			pthread_mutex_t *mutex)
{
	size_t	mutex_right;
	size_t	mutex_left;

	get_mutex_for_thread(caller_id, thread_num, &mutex_right, &mutex_left);
	pthread_mutex_lock(mutex + mutex_right);
	print_message(caller_id, MSG_FORK, mutex + thread_num);
	pthread_mutex_lock(mutex + mutex_left);
	print_message(caller_id, MSG_FORK, mutex + thread_num);
}

void	unlock_mutex(size_t const caller_id, size_t const thread_num,
			pthread_mutex_t *mutex)
{
	size_t	mutex_right;
	size_t	mutex_left;

	get_mutex_for_thread(caller_id, thread_num, &mutex_right, &mutex_left);
	pthread_mutex_unlock(mutex + mutex_right);
	pthread_mutex_unlock(mutex + mutex_left);
}
