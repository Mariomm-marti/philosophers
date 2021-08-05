/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:29:45 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/05 18:10:04 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <philosophers.h>

t_philo	*get_philo(t_philo const *philos, unsigned int const philo_id)
{
	return ((t_philo *)(philos + philo_id - 1));
}

t_philo	*create_philos(unsigned int const philo_num)
{
	t_philo			*philos;
	t_philo			*current_philo;
	unsigned int	current_philo_id;

	philos = malloc(sizeof(t_philo) * philo_num);
	if (!philos)
		return (NULL);
	current_philo_id = 1;
	while (current_philo_id <= philo_num)
	{
		current_philo = get_philo(philos, current_philo_id);
		current_philo->id = current_philo_id;
		pthread_create(&(current_philo->thread), NULL, worker, current_philo);
		current_philo_id++;
	}
	return (philos);
}
