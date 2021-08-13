/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:08:20 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/13 19:04:39 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <routine.h>
#include <common.h>

static void	merge_threads(pthread_t *threads, size_t const thread_num)
{
	size_t current_thread;

	current_thread = 0;
	while (current_thread < thread_num)
	{
		pthread_join(*(threads + current_thread), NULL);
		current_thread++;
	}
}

int	main(void)
{
	int				all_alive;
	pthread_mutex_t	*mutex;
	t_routine		*routines;
	pthread_t		*threads;

	all_alive = TRUE;
	mutex = init_mutex(4);
	routines = init_routines(4, &all_alive, mutex);
	get_timestamp(1);
	threads = init_threads(4, routines);
	while (all_alive == TRUE)
	{
		wrap_usleep(4000, 4);
		all_alive = FALSE;
		pthread_mutex_lock(mutex + 4);
	}
	merge_threads(threads, 4);
	free(threads);
	free(routines);
	free(mutex);
	system("leaks philo");
	return (0);
}
