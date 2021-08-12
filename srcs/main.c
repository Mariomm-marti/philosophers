/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:08:20 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/12 20:11:53 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <pthread.h>
#include <routine.h>

#include <stdio.h>
pthread_mutex_t	*init_mutex(size_t const mutex_num)
{
	pthread_mutex_t	*mutex;
	size_t			current_mutex;

	mutex = malloc(sizeof(pthread_mutex_t) * mutex_num);
	if (!mutex)
		return (NULL);
	current_mutex = 0;
	while (current_mutex < mutex_num)
	{
		pthread_mutex_init(mutex + current_mutex, NULL);
		current_mutex++;
	}
	return (mutex);
}

static t_routine	init_routine(size_t const caller_id,
		size_t const thread_num, pthread_mutex_t *mutex)
{
	t_routine	new_routine;

	new_routine.caller_id = caller_id;
	new_routine.thread_num = thread_num;
	new_routine.mutex = mutex;
	return (new_routine);
}

pthread_t	*init_threads(size_t const thread_num, pthread_mutex_t *mutex)
{
	pthread_t	*threads;
	t_routine	thread_routine;
	size_t		current_thread;

	threads = malloc(sizeof(pthread_t) * thread_num);
	if (!threads)
		return (NULL);
	current_thread = 0;
	while (current_thread < thread_num)
	{
		thread_routine = init_routine(current_thread, thread_num, mutex);
		pthread_create(threads + current_thread, NULL, routine, &thread_routine);
		current_thread++;
	}
	return (threads);
}

int		main(void)
{
	pthread_mutex_t	*mutex;
	pthread_t		*threads;

	mutex = init_mutex(10);
	threads = init_threads(10, mutex);
	while (1)
		;
}
