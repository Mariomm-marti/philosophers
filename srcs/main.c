/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:08:20 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/17 17:57:52 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <routine.h>
#include <common.h>
#include <params.h>

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
		t_timestamp const time_to_die)
{
	t_timestamp const	current_time = get_timestamp(0);
	size_t const		total_routines = routines->thread_num;
	size_t				current;

	current = 0;
	while (current < total_routines)
	{
		if (current_time - (routines + current)->last_eat > time_to_die)
		{
			printf("RIP %zu: time elapsed %ld\n", current,
					current_time - (routines + current)->last_eat);
			return (FALSE);
		}
		current++;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	int				all_alive;
	t_params		params;
	pthread_mutex_t	*mutex;
	t_routine		*routines;
	pthread_t		*threads;

	all_alive = TRUE;
	if (parser_validate(argc, argv) == FALSE)
	{
		printf("Error: invalid arguments\n");
		return (1);
	}
	params = parser_fetch(argv);
	if (params.philos == 1)
	{
		printf("0 1 died\n");
		return (0);
	}
	mutex = init_mutex(params.philos);
	routines = init_routines(params.philos, &all_alive, params, mutex);
	get_timestamp(1);
	threads = init_threads(params.philos, routines);
	while (all_alive == TRUE)
	{
		wrap_usleep(20, params.philos);
		if (verify_philos_alive(routines, params.die) == FALSE)
			all_alive = FALSE;
	}
	merge_threads(threads, params.philos);
	free(threads);
	free(routines);
	free(mutex);
	system("leaks philo");
	return (0);
}
