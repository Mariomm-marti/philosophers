/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:08:20 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/17 22:24:38 by mmartin-         ###   ########.fr       */
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

static void	main_loop(int *all_alive, t_params params, pthread_mutex_t *mutex,
		t_routine *routines)
{
	t_timestamp	trn;
	t_timestamp	total;
	int			count;

	while (*all_alive == TRUE)
	{
		trn = get_timestamp(0);
		count = 0;
		while (count < params.philos)
		{
			pthread_mutex_lock(mutex + params.philos);
			total = trn - (routines + count)->last_eat;
			if (total > params.die && *all_alive == TRUE)
			{
				printf("%ld %zu died\n", get_timestamp(0), (routines + count)->caller_id + 1);
				*all_alive = FALSE;
			}
			pthread_mutex_unlock(mutex + params.philos);
			count++;
		}
		wrap_usleep(10, params.philos);
	}
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
		printf("0 1 has taken a fork\n");
		wrap_usleep(params.die, 1);
		printf("%zu 1 died\n", params.die);
		return (0);
	}
	mutex = init_mutex(params.philos);
	routines = init_routines(params.philos, &all_alive, params, mutex);
	get_timestamp(1);
	threads = init_threads(params.philos, routines);
	main_loop(&all_alive, params, mutex, routines);
	merge_threads(threads, params.philos);
	free(threads);
	free(routines);
	free(mutex);
	system("leaks philo");
	return (0);
}
