/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:05:31 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/13 18:33:02 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>
#include <unistd.h>
#include <sys/time.h>

static t_timestamp	get_current_millis(void)
{
	struct timeval	tp;

	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

t_timestamp	get_timestamp(int is_first)
{
	static t_timestamp	initial_timestamp = 0;

	if (is_first)
		initial_timestamp = get_current_millis();
	return (get_current_millis() - initial_timestamp);
}

void	wrap_usleep(size_t const ms, size_t const interval)
{
	t_timestamp const	init = get_timestamp(0);

	while (get_timestamp(0) - init < ms)
		usleep(interval);
}
