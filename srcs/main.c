/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 19:08:20 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/13 18:15:49 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <routine.h>
#include <common.h>

int	main(void)
{
	int				all_alive;
	pthread_mutex_t	*mutex;
	t_routine		*routines;
	pthread_t		*threads;

	all_alive = TRUE;
	mutex = init_mutex(3);
	routines = init_routines(3, &all_alive, mutex);
	get_timestamp(1);
	threads = init_threads(3, routines);
	while (all_alive)
		;
	free(threads);
	free(routines);
	free(mutex);
	system("leaks philo");
	return (0);
}
