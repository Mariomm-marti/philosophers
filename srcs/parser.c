/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:30:15 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/11 19:23:07 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <table.h>
#include <utils.h>

static t_bool	validate_argument(char const *str)
{
	unsigned long long	ret;

	ret = 0;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		if (ret > MAX_TIMESTAMP)
			return (false);
		str++;
	}
	if (*str)
		return (false);
	return (true);
}

t_bool	parser_validate(int argc, char **argv)
{
	short	count;

	if (argc != 5 && argc != 6)
		return (false);
	count = 1;
	while (*(argv + count))
	{
		if (!validate_argument(*(argv + count)))
			return (false);
		count++;
	}
	return (true);
}

t_params	parser_fetch(char **argv)
{
	t_params	input;

	input.philos = ft_strtoul(*(argv + 1));
	input.die = ft_strtoul(*(argv + 2));
	input.eat = ft_strtoul(*(argv + 3));
	input.sleep = ft_strtoul(*(argv + 4));
	input.amount = ft_strtoul(*(argv + 5));
	return (input);
}
