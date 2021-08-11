/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartin- <mmartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 19:30:07 by mmartin-          #+#    #+#             */
/*   Updated: 2021/08/11 20:07:28 by mmartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <validate.h>
#include <table.h>
#include <timestamps.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static t_bool	initialize_table(t_worker *worker)
{
	worker->forks = create_forks(params.philos);
	if (worker->forks == false)
		return (false);
	worker->philos = create_philos(params.philos, worker);
	if (worker->philos == false)
	{
		free(worker->forks);
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_worker	worker;

	if (!parser_validate(argc, argv))
	{
		printf("Error: invalid parameters\n");
		return (1);
	}
	worker.params = parser_fetch(argv);
	if (initialize_table(&worker) == false)
		return (1);
	free(worker.forks);
	free(worker.philos);
	system("leaks philo");
}
