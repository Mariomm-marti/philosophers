/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:41:34 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/12 18:14:40 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <table.h>
#include <stddef.h>
#include <stdlib.h>

t_fork	*get_left_fork(size_t const philo_id, size_t const philo_num,
		t_fork *forks)
{
	if (philo_id == 0)
		return (forks + philo_num);
	return (forks + philo_id - 1);
}

t_fork	*get_right_fork(size_t const philo_id, t_fork *forks)
{
	return (forks + philo_id);
}

void	destroy_forks(size_t const fork_number, t_fork *forks)
{
	t_fork	*current_fork;
	size_t	current_fork_id;

	current_fork_id = 0;
	while (current_fork_id < fork_number)
	{
		current_fork = *(forks + current_fork_id);
		pthread_mutex_destroy(current_fork);
		current_fork_id++;
	}
	free(forks);
}

t_fork	*create_forks(size_t const fork_number)
{
	t_fork	*forks;
	t_fork	*current_fork;
	size_t	current_fork_id;

	forks = malloc(sizeof(t_fork) * fork_number);
	if (forks == FAILED)
		return (NULL);
	current_fork_id = 0;
	while (current_fork_id < fork_number)
	{
		current_fork = *(forks + current_fork_id);
		if (pthread_mutex_init(current_fork, NULL) != false)
		{
			destroy_forks(fork_number, forks);
			return (NULL);
		}
		current_fork_id++;
	}
	return (forks);
}
