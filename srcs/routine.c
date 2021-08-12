/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:54:03 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/12 17:56:17 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philos.h>
#include <timestamps.h>

static void	execute_philo(t_philo const *current_philo,
		t_params const *params, t_fork const *forks, t_timestamp *ref_time)
{
	while (*ref_time != 0)
	{
		pickup_fork(current_philo->id, params->philos, forks, true);
		printf("%d has picked a fork\n", current_philo->id);
		pickup_fork(current_philo->id, params->philos, forks, false);
		printf("%d has picked a fork\n", current_philo->id);
		usleep(400);
		pthread_mutex_unlock(get_left_fork(current_philo->id, params->philos,
					forks));
		pthread_mutex_unlock(get_right_fork(current_philo->id, forks));
	}
}

void	*routine(void *arg)
{
	t_worker	*worker;
	t_philo		*current_philo;
	t_params	*params;
	t_fork		*forks;
	t_timestamp	*ref_time;

	worker = (t_worker *)arg;
	current_philo = get_philo(worker->philos, worker->caller);
	params = worker->params;
	forks = worker->forks;
	ref_time = &(worker->ref_time);
	execute_philo(current_philo, params, forks, ref_time);
	return (NULL);
}
