/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 13:41:34 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/11 19:28:13 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <table.h>
#include <stddef.h>
#include <stdlib.h>

t_fork	*get_fork(t_fork *forks, size_t const fork_number)
{
	return (forks + fork_number - 1);
}

t_fork	*create_forks(size_t const fork_amount)
{
	t_fork	*forks;
	t_fork	*current_fork;
	size_t	current_fork_id;

	forks = malloc(sizeof(t_fork) * fork_amount);
	if (forks == FAILED)
		return (NULL);
	current_fork_id = 1;
	while (current_fork_id <= fork_amount)
	{
		current_fork = get_fork(forks, current_fork_id);
		if (pthread_mutex_init(current_fork, NULL) != false)
		{
			free(forks);
			return (NULL);
		}
		current_fork++;
	}
	return (forks);
}
