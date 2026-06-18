/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:17:03 by bfernan2          #+#    #+#             */
/*   Updated: 2026/06/18 17:17:13 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philos;

	memset(&data, 0, sizeof(t_data));
	philos = NULL;
	if (parse_arguments(argc, argv, &data) == -1)
	{
		printf("ERROR: Invalid arguments\n");
		return (1);
	}
	if (init_data(&data, &philos) == -1)
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	if (run_simulation(&data, &philos) == -1)
	{
		cleanup(&data, philos);
		return (1);
	}
	cleanup(&data, philos);
	return (0);
}