/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:01:38 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/12 18:06:14 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORKS_H
# define FORKS_H

typedef pthread_mutex_t	t_fork;

t_fork	*get_fork(t_fork *forks, size_t const fork_number);
t_fork	*get_left_fork(size_t const philo_id, size_t const philo_num,
			t_fork *forks);
t_fork	*get_right_fork(size_t const philo_id, t_fork *forks);
t_fork	*create_forks(size_t const fork_number);
void	destroy_forks(size_t const fork_number, t_fork *forks);

#endif
