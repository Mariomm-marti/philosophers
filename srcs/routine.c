/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:40:22 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/17 22:22:56 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <routine.h>
#include <common.h>

void	*routine(void *arg)
{
	t_routine	*data;

	data = (t_routine *)arg;
	while (*(data->all_alive) == TRUE)
	{
		lock_mutex(data->caller_id, data->thread_num, data->mutex,
			data->all_alive);
		data->last_eat = get_timestamp(0);
		print_message(data->caller_id, MSG_EAT,
			data->all_alive, data->mutex + data->thread_num);
		wrap_usleep(data->params.eat, data->thread_num);
		unlock_mutex(data->caller_id, data->thread_num, data->mutex);
		print_message(data->caller_id, MSG_SLP,
			data->all_alive, data->mutex + data->thread_num);
		wrap_usleep(data->params.sleep, data->thread_num);
		print_message(data->caller_id, MSG_THK,
			data->all_alive, data->mutex + data->thread_num);
	}
	return (NULL);
}
