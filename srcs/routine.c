/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:40:22 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/13 19:15:40 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <routine.h>
#include <common.h>

void	*routine(void *arg)
{
	t_routine const	*data = (t_routine *)arg;

	if (data->caller_id % 2 != 0)
		usleep(100);
	while (*(data->all_alive) == TRUE)
	{
		lock_mutex(data->caller_id, data->thread_num, data->mutex,
				*(data->all_alive));
		print_message(data->caller_id, MSG_EAT, *(data->all_alive));
		wrap_usleep(60, data->thread_num);
		unlock_mutex(data->caller_id, data->thread_num, data->mutex);
		print_message(data->caller_id, MSG_SLP, *(data->all_alive));
		wrap_usleep(60, data->thread_num);
		print_message(data->caller_id, MSG_THK, *(data->all_alive));
	}
	return (NULL);
}
