/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:30:15 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/17 17:52:07 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common.h>

static size_t	ft_stozu(char const *str)
{
	size_t	num;

	if (!str)
		return (0);
	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

static int	validate_argument(char const *str, int force_minskip)
{
	unsigned long long	ret;

	if (!str)
		return (0);
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
	if (force_minskip == FALSE && ret < MIN_TIMESTAMP)
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
		if (!validate_argument(*(argv + count), count == 1))
			return (0);
		count++;
	}
	return (1);
}

t_params	parser_fetch(char **argv)
{
	t_params	input;

	input.philos = ft_stozu(*(argv + 1));
	input.die = ft_stozu(*(argv + 2));
	input.eat = ft_stozu(*(argv + 3));
	input.sleep = ft_stozu(*(argv + 4));
	input.amount = ft_stozu(*(argv + 5));
	return (input);
}
