/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:30:21 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/05 18:06:11 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <table.h>
#include <unistd.h>

unsigned long	ft_strtoul(char const *str)
{
	unsigned long	ret;

	if (!str)
		return (0);
	ret = 0;
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (ret);
}
