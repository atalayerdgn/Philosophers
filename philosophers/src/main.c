/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerdogan <aerdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 21:22:42 by aerdogan          #+#    #+#             */
/*   Updated: 2024/01/20 14:10:49 by aerdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <stdlib.h>
#include <stdio.h>

int	parser(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		if (!argv[i] || !*argv[i])
			return (1);
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				;
			else
				return (1);
		}
	}
	return (0);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->d_lock);
	if (philo->data->is_dead == 1)
	{
		pthread_mutex_unlock(&philo->data->d_lock);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->d_lock);
	return (0);
}

int	err(char *str)
{
	printf("%s\n", str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (err("ERROR - 1:Wrong number of parameters"));
	if (parser(argv) == 1)
		return (err("ERROR - 1:Wrong parameters"));
	if (load(&data, argc, argv))
		return (1);
	philo_create(&data, -1);
	free(data.tid);
	free(data.philo);
	free(data.forks);
	return (0);
}
