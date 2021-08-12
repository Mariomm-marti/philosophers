/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:29:45 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/11 18:38:31 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <table.h>
#include <timestamps.h>

t_philo	*get_philo(t_philo *philos, size_t const philo_id)
{
	return (philos + philo_id - 1);
}

void	destroy_philos(t_philo *philos, size_t const philo_num)
{
	t_philo	*current_philo;
	size_t	current_philo_id;

	current_philo_id = 1;
	while (current_philo_id <= philo_num)
	{
		current_philo = get_philo(philos, current_philo_id);
		pthread_join(current_philo->thread);
		current_philo_id++;
	}
	free(philos);
}

t_philo	*create_philos(size_t const philo_num, t_worker *work)
{
	t_philo	*philos;
	t_philo	*current_philo;
	size_t	current_philo_id;

	philos = malloc(sizeof(t_philo) * philo_num);
	if (philos == FAILED)
		return (NULL);
	initialize_timestamp(philos, philo_num);
	current_philo_id = 1;
	while (current_philo_id <= philo_num)
	{
		current_philo = get_philo(philos, current_philo_id);
		current_philo->id = current_philo_id;
		if (pthread_create(&(current_philo->thread), NULL, callb,
				current_philo) != false)
		{
			free(philos);
			return (NULL);
		}
		current_philo_id++;
	}
	return (philos);
}
