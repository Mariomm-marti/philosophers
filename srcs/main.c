/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:08:20 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/13 19:21:55 by mmartin-         ###   ########.fr       */
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
	size_t	current_thread;

	current_thread = 0;
	while (current_thread < thread_num)
	{
		pthread_join(*(threads + current_thread), NULL);
		current_thread++;
	}
}

static int	verify_philos_alive(t_routine const *routines,
		t_timestamp const eat_period)
{
	size_t const	total_routines = routines->thread_num;
	size_t			current;

	current = 0;
	while (current < total_routines)
	{
		if (get_timestamp(0) - (routines + current)->last_eat > eat_period)
		{
			printf("RIP %zu: time elapsed %ld\n", current,
					get_timestamp(0) - (routines + current)->last_eat);
			return (FALSE);
		}
		current++;
	}
	return (TRUE);
}

int	main(void)
{
	int				all_alive;
	pthread_mutex_t	*mutex;
	t_routine		*routines;
	pthread_t		*threads;

	all_alive = TRUE;
	mutex = init_mutex(200);
	routines = init_routines(200, &all_alive, mutex);
	get_timestamp(1);
	threads = init_threads(200, routines);
	while (all_alive == TRUE)
	{
		wrap_usleep(20, 200);
		if (verify_philos_alive(routines, 130) == FALSE)
			all_alive = FALSE;
	}
	merge_threads(threads, 200);
	free(threads);
	free(routines);
	free(mutex);
	system("leaks philo");
	return (0);
}
