/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:29:45 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/12 18:01:13 by mmartin-         ###   ########.fr       */
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
