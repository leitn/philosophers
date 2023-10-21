/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:57:09 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/21 12:41:37 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	ft_init_args(int argc, char *argv[], t_data *data)
{
	if (ft_check_args(argc, argv) == 1)
		return (1);
	data->nb_philo = ft_atol(argv[1]);
	data->time_to_die = ft_atoll(argv[2]);
	data->time_to_eat = ft_atoll(argv[3]);
	data->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
			data->nb_max_meals = ft_atoi(argv[5]);
	else
		data->nb_max_meals = -2;
	data->finished_dinner = 0;
	data->dead_man_among_us = 0;
	if (data->nb_philo == -1 || data->time_to_die == -1
		|| data->time_to_eat == -1 || data->time_to_sleep == -1
		|| data->nb_max_meals == -1 || data->nb_philo == 0)
		return (1);
	return (0);
}
