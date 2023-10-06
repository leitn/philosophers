/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:04 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 09:56:12 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// To make while having incomplete functions
void	do_nothing_but_make(t_data *data)
{
	int	memento_mori;

	memento_mori = data->time_to_die;
}

//routine
void	*ft_routine(void *ph_philo)
{
	t_philo		*philo;

	philo = (t_philo *) ph_philo;
	philo->time_of_eating = ft_get_time() - philo->data->start_time;
	while (death_status(philo) != DIED)
	{
		if (ft_eat(philo) != 0)
			break ;
		if (death_status(philo) == DIED)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (death_status(philo) == DIED)
			break ;
		if (ft_think(philo) != 0)
			break ;
	}
	return (NULL);
}

//pthread create and send to routine
int	ft_start_routine(t_data	*data)
{
	int			i;
	int			ph_nb_philo;

	i = 0;
	ph_nb_philo = data->nb_philo;
	while (i < ph_nb_philo)
	{
		if (pthread_create(&data->philo_threads[i], NULL,
				&ft_routine, &data->philos[i]))
		{
			ft_pthread_join(data);
			return (1);
		}
		if (is_someone_dead(data) == 1)
		{
			printf("Someone died. RIP\n");
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

