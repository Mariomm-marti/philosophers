/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:30:15 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/13 19:22:56 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

static int	validate_argument(char const *str)
{
	unsigned long long	ret;

	ret = 0;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		if (ret > MAX_TIMESTAMP)
			return (0);
		str++;
	}
	if (*str)
		return (0);
	return (1);
}

int	parser_validate(int argc, char **argv)
{
	short	count;

	if (argc != 5 && argc != 6)
		return (0);
	count = 1;
	while (*(argv + count))
	{
		if (!validate_argument(*(argv + count)))
			return (0);
		count++;
	}
	return (1);
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
