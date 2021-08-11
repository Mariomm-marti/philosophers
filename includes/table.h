/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:29:56 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/11 19:21:11 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# define MAX_TIMESTAMP 4294967295U
# define FAILED 0

# include <pthread.h>

typedef long			t_timestamp;
typedef pthread_mutex_t	t_fork;

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_philo
{
	size_t		id;
	t_timestamp	initial_timestamp;
	pthread_t	thread;
}	t_philo;

typedef struct s_params
{
	size_t	philos;
	size_t	amount;
	size_t	die;
	size_t	eat;
	size_t	sleep;
}	t_params;

typedef struct s_worker
{
	t_params	params;
	t_philo		*philos;
	t_fork		*forks;
}	t_worker;

void		*worker(void *self);

t_fork		*create_forks(size_t const fork_amount);
t_fork		*get_fork(t_fork *forks, size_t const fork_number);

t_philo		*create_philos(size_t const philo_num,
				void *(*f)(void *arg));
t_philo		*get_philo(t_philo *philos, size_t const philo_id);

#endif
