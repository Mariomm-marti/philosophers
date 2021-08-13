/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:48:57 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/13 19:16:03 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <common.h>

void	print_message(size_t const philo_num, char const *message,
		int const all_alive)
{
	if (!all_alive)
		return ;
	printf(message, get_timestamp(0), philo_num);
}
