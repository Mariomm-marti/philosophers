/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:30:07 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/11 13:41:55 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <validate.h>
#include <philosophers.h>
#include <timestamps.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_params	params;
	t_philo		*philos;

	if (!parser_validate(argc, argv))
	{
		printf("Error: invalid parameters\n");
		return (1);
	}
	parser_fetch(&params, argv);
	philos = create_philos(params.philos, worker);
	free(philos);
	system("leaks philo");
}
