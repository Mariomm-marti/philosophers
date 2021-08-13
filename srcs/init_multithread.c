/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_multithread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:06:52 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/13 17:46:41 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <pthread.h>
#include <routine.h>
#include <common.h>

pthread_mutex_t	*init_mutex(size_t const mutex_num)
{
	pthread_mutex_t	*mutex;
	size_t			current_mutex;

	mutex = malloc(sizeof(pthread_mutex_t) * (mutex_num + 1));
	if (!mutex)
		return (NULL);
	current_mutex = 0;
	while (current_mutex <= mutex_num)
	{
		pthread_mutex_init(mutex + current_mutex, NULL);
		current_mutex++;
	}
	return (mutex);
}

t_routine	*init_routines(size_t const thread_num, int *all_alive,
		pthread_mutex_t *mutex)
{
	t_routine	*new_routines;
	size_t		current_routine;

	new_routines = malloc(sizeof(t_routine) * thread_num);
	if (!new_routines)
		return (NULL);
	current_routine = 0;
	while (current_routine < thread_num)
	{
		(new_routines + current_routine)->caller_id = current_routine;
		(new_routines + current_routine)->thread_num = thread_num;
		(new_routines + current_routine)->all_alive = all_alive;
		(new_routines + current_routine)->mutex = mutex;
		current_routine++;
	}
	return (new_routines);
}

pthread_t	*init_threads(size_t const thread_num, t_routine *routines)
{
	pthread_t	*threads;
	size_t		current_thread;

	threads = malloc(sizeof(pthread_t) * thread_num);
	if (!threads)
		return (NULL);
	current_thread = 0;
	while (current_thread < thread_num)
	{
		pthread_create(threads + current_thread, NULL, routine,
			routines + current_thread);
		current_thread++;
	}
	return (threads);
}
