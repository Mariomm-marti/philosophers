/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timestamps.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:36:57 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/05 19:18:17 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMESTAMPS_H
# define TIMESTAMPS_H

typedef long	t_timestamp;

t_timestamp		get_timestamp(t_timestamp const original_timestamp);
void			initialize_timestamp(unsigned int philo_num,
					t_philo const *philos);

#endif
