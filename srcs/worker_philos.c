/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:41:03 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/05 19:17:14 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <stdio.h>

void	*worker(void *self)
{
	t_philo const	*philo_self;

	philo_self = (t_philo const *)self;
	printf("[timestamp] %d is eating\n", philo_self->id);
	return (NULL);
}
