/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:48:57 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/13 18:16:25 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <common.h>

void	print_message(size_t const philo_num, char const *message,
		pthread_mutex_t *mutex_out)
{
	pthread_mutex_lock(mutex_out);
	printf(message, get_timestamp(0), philo_num);
	fflush(stdout);
	pthread_mutex_unlock(mutex_out);
}
