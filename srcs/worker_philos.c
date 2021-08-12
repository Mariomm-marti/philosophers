/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worker_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:41:03 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/11 13:41:28 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <table.h>
#include <timestamps.h>
#include <stdio.h>
#include <unistd.h>

void	*worker(void *self)
{
	t_worker	*work;

	work = (t_worker *)self;
	while (philo_self->thread != NULL)
	{
		take_forks
	}
	return (NULL);
}
