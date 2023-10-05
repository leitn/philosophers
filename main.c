/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:04 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/05 12:30:31 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// To make while having incomplete functions
void	do_nothing_but_make(t_data *data)
{
	int	memento_mori;

	memento_mori = 0;
	memento_mori = data->time_to_die;
}

//WIP (obviously)
void	*ft_routine(void *ph_philo)
{
	t_philo		*philo;

	philo = (t_philo *) ph_philo;
	philo->time_of_eating = ft_get_time() - philo->data->start_time;
	if (pthread_mutex_lock(&philo->data->mut_print) == 0)
		printf("\n PHILO %i EATS AT %lldms", philo->philo_id,
			philo->time_of_eating);
	pthread_mutex_unlock(&philo->data->mut_print);
	ft_eat(philo);
	return (NULL);
}

//pthread create and send to routine
int	ft_start_routine(t_data	*data)
{
	int			i;

	i = 0;
	data->start_time = ft_get_time();
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo_threads[i], NULL,
				&ft_routine, &data->philos[i]))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (ft_init_args(argc, argv, &data) != 0)
		{
			printf("invalid arguments\n");
			return (1);
		}
		if (ft_init_data(&data) != 0)
		{
			ft_error(&data);
			return (1);
		}
		ft_start_routine(&data);
		if (ft_pthread_join(&data) != 0)
		{
			ft_error(&data);
			return (1);
		}
		ft_free_data(&data);
	}
	return (0);
}

