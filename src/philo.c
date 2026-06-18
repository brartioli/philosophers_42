/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfernan2 <bfernan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:18:17 by bfernan2          #+#    #+#             */
/*   Updated: 2026/06/18 17:53:27 by bfernan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	create_threads(t_data *data, t_philo *philos, pthread_t *monitor)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine,
				&philos[i]) != 0)
			return (-1);
		i++;
	}
	if (pthread_create(monitor, NULL, monitor_routine, philos) != 0)
		return (-1);
	return (0);
}

static void	join_threads(t_data *data, t_philo *philos, pthread_t monitor)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor, NULL);
}

int	run_simulation(t_data *data, t_philo **philos)
{
	pthread_t	monitor;

	if (create_threads(data, *philos, &monitor) == -1)
	{
		printf("Error: Thread creation failed\n");
		return (-1);
	}
	join_threads(data, *philos, monitor);
	return (0);
}
