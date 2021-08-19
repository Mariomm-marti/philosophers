/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:13:06 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/19 20:56:48 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <pthread.h>
# include <routine.h>

# define MAX_TIMESTAMP 20000
# define MIN_TIMESTAMP 60

# define FALSE 0
# define TRUE 1
# define MSG_FORK "%ld %zu has taken a fork\n"
# define MSG_EAT "%ld %zu is eating\n"
# define MSG_SLP "%ld %zu is sleeping\n"
# define MSG_THK "%ld %zu is thinking\n"
# define MSG_DEAD "%ld %zu died\n"
# define MSG_EATF "%ld %zu finished eating\n"

typedef size_t	t_timestamp;

t_timestamp			get_timestamp(int is_first);
void				wrap_usleep(size_t const ms, size_t const interval);

void				print_message(size_t const philo_num, char const *message,
						int *all_alive, pthread_mutex_t *mutex_out);

pthread_mutex_t		*init_mutex(size_t const mutex_num);
t_routine			*init_routines(size_t const thread_num, int *all_alive,
						t_params const params, pthread_mutex_t *mutex);
pthread_t			*init_threads(size_t const thread_num, t_routine *routines);

#endif
