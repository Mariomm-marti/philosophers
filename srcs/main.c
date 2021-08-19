/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:08:20 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/19 21:07:07 by mmartin-         ###   ########.fr       */
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

static int	remain_feeding(t_routine *routines, int thread_num)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < thread_num)
	{
		if ((routines + i)->last_eat == MAX_TIMESTAMP)
			count++;
		i++;
	}
	return (count != thread_num);
}

static void	main_loop(int *all_alive, t_params params, pthread_mutex_t *mutex,
		t_routine *routines)
{
	t_timestamp	trn;
	t_timestamp	total;
	int			count;
	int			skip;

	wrap_usleep(60, params.philos);
	while (*all_alive == TRUE && remain_feeding(routines, params.philos))
	{
		trn = get_timestamp(0);
		count = 0;
		skip = 0;
		while (count < params.philos)
		{
			total = trn - (routines + count)->last_eat;
			pthread_mutex_lock(mutex + params.philos);
			if (total > params.die && *all_alive == TRUE
				&& (routines + count)->last_eat != MAX_TIMESTAMP)
			{
				printf("%ld %zu died\n", get_timestamp(0),
					(routines + count)->caller_id + 1);
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
		return (!!printf("0 1 has taken a fork\n%zu 1 died\n", params.die));
	mutex = init_mutex(params.philos);
	routines = init_routines(params.philos, &all_alive, params, mutex);
	get_timestamp(1);
	threads = init_threads(params.philos, routines);
	main_loop(&all_alive, params, mutex, routines);
	merge_threads(threads, params.philos);
	free(threads);
	free(routines);
	free(mutex);
	return (0);
}
