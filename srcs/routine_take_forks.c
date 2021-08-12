/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_take_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:48:32 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/12 17:50:13 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <table.h>
#include <routine.h>

static t_bool	is_right_fork(size_t const philo_id, t_bool const is_first_fork)
{
	if (philo_id % 2 == 0 && is_first_fork == true)
		return (true);
	if (philo_id % 2 != 0 && is_first_fork == true)
		return (false);
	if (philo_id % 2 == 0 && is_first_fork == false)
		return (false);
	return (true);
}

void	pickup_fork(size_t const philo_id, t_fork const *forks,
		size_t const philo_amount, t_bool const is_first_fork)
{
	if (is_right_fork(philo_id, is_first_fork) == true)
	{
		pthread_mutex_lock(get_right_fork(philo_id, forks));
		return ;
	}
	pthread_mutex_lock(get_left_fork(philo_id, forks));
}
