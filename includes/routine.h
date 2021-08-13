/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:35:33 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/13 17:01:48 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include <stddef.h>
# include <pthread.h>

typedef struct s_routine
{
	size_t			caller_id;
	size_t			thread_num;
	int				*all_alive;
	pthread_mutex_t	*mutex;
}	t_routine;

void	lock_mutex(size_t const caller_id, size_t const thread_num,
			pthread_mutex_t *mutex);
void	unlock_mutex(size_t const caller_id, size_t const thread_num,
			pthread_mutex_t *mutex);

void	*routine(void *arg);

#endif
