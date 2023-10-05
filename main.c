/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:04 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/05 16:15:13 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// To make while having incomplete functions
void	do_nothing_but_make(t_data *data)
{
	int	memento_mori;

	memento_mori = data->time_to_die;
}

//WIP (obviously), Too long
void	*ft_routine(void *ph_philo)
{
	t_philo		*philo;

	philo = (t_philo *) ph_philo;
	philo->time_of_eating = ft_get_time(philo->data);
	if (pthread_mutex_lock(&philo->data->mut_print) == 0)
	{
		printf("\n PHILO %i EATS AT %lldms", philo->philo_id,
			philo->time_of_eating);
	}
	pthread_mutex_unlock(&philo->data->mut_print);
	while (death_status(philo) != DIED)
	{
		if (ft_eat(philo) != 0)
		{
			if (ft_think(philo) == 1)
			{
				if (pthread_mutex_lock(&philo->data->mut_print) == 0)
					printf("\n PHILO %i THINKS", philo->philo_id);
				pthread_mutex_unlock(&philo->data->mut_print);
			}
			else if (philo->status == THINKING)
				usleep(100);
		}
		else
			ft_sleep(philo);
	}
	return (NULL);
}

//pthread create and send to routine
int	ft_start_routine(t_data	*data)
{
	int			i;

	i = 0;
	data->start_time = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo_threads[i], NULL,
				&ft_routine, &data->philos[i]))
			return (1);
		if (is_someone_dead(data) == 1)
		{
			printf("Someone died. RIP");
			ft_error(data);
			return (1);
		}
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

