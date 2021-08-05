/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:41:03 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/05 19:54:36 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <timestamps.h>
#include <stdio.h>

void	*worker(void *self)
{
	t_philo const	*philo_self;

	philo_self = (t_philo const *)self;
	printf("%ld %d is eating\n", get_timestamp(philo_self->initial_timestamp),
				philo_self->id);
	return (NULL);
}
