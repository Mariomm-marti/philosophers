/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:11:52 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/17 17:27:56 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

typedef size_t	t_timestamp;

typedef struct s_params
{
	int			philos;
	int			amount;
	t_timestamp	die;
	t_timestamp	eat;
	t_timestamp	sleep;
}	t_params;

int			parser_validate(int argc, char **argv);
t_params	parser_fetch(char **argv);

#endif
