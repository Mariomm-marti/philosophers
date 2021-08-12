/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:29:56 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/12 18:07:59 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# define MAX_TIMESTAMP 4294967295U
# define FAILED 0

# include <pthread.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_philo
{
	size_t		id;
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

t_philo		*create_philos(size_t const philo_num, t_worker *work);
t_philo		*get_philo(t_philo *philos, size_t const philo_id);

#endif
