/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:29:56 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/11 13:42:31 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define MAX_TIMESTAMP 4294967295U

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
	unsigned int		id;
	t_timestamp			initial_timestamp;
	pthread_t			thread;
}	t_philo;

typedef struct s_params
{
	unsigned int	philos;
	unsigned int	amount;
	unsigned int	die;
	unsigned int	eat;
	unsigned int	sleep;
}	t_params;

typedef struct s_worker
{
	t_philo		*philos;
	t_params	*params;
	t_fork		*forks;
}	t_worker;

void		*worker(void *self);

t_philo		*create_philos(unsigned int const philo_num,
				void *(*f)(void *arg));
t_philo		*get_philo(t_philo const *philos, unsigned int const philo_id);
void		free_philos(t_philo *master);

#endif
