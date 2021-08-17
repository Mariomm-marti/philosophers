/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:48:57 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/17 22:22:39 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <common.h>

void	print_message(size_t const philo_num, char const *message,
		int *all_alive, pthread_mutex_t *mutex_out)
{
	t_timestamp const	msg_time = get_timestamp(0);

	pthread_mutex_lock(mutex_out);
	if (*all_alive)
		printf(message, msg_time, philo_num + 1);
	pthread_mutex_unlock(mutex_out);
}
