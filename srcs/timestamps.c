/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:28:36 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/05 19:40:03 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <timestamps.h>
#include <philosophers.h>

t_timestamp	get_timestamp(t_timestamp const original_timestamp)
{
	struct timeval	tp;
	t_timestamp		current;

	if (gettimeofday(&tp, NULL) == -1)
		return (-1);
	current = tp.tv_sec * 1000 + tp.tv_usec / 1000;
	return (current - original_timestamp);
}

void	initialize_timestamp(unsigned int philo_num, t_philo const *philos)
{
	t_philo			*current;
	t_timestamp		initial_timestamp;
	unsigned int	current_philo_id;

	initial_timestamp = get_timestamp(0);
	current_philo_id = 1;
	while (current_philo_id <= philo_num)
	{
		current = get_philo(philos, current_philo_id);
		current->initial_timestamp = initial_timestamp;
		current_philo_id++;
	}
}
