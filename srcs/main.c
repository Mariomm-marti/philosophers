/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:30:07 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/05 20:24:58 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <validate.h>
#include <philosophers.h>
#include <timestamps.h>
#include <utils.h>
#include <stdio.h>
#include <stdlib.h>

void	merge_philos(t_philo const *philos, unsigned int const philos_num)
{
	unsigned int	current_philo_id;

	current_philo_id = 1;
	while (current_philo_id <= philos_num)
	{
		pthread_join(get_philo(philos, current_philo_id)->thread, NULL);
		current_philo_id++;
	}
}

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
	philos = create_philos(params.philos);
	merge_philos(philos, params.philos);
	system("leaks philo");
}
