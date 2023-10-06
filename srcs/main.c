/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:04 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 16:59:46 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//join threads, returns 1 if error
int	ft_pthread_join(t_data *data)
{
	int	i;
	int	nb;

	i = 0;
	nb = ft_get_nb_philos(data);
	while (i < nb)
	{
		if (pthread_join(data->philo_threads[i], NULL))
			return (1);
		i++;
	}
	if (pthread_join(data->monitor, NULL))
			return (1);
	return (0);
}

//routine
void	*ft_routine(void *ph_philo)
{
	t_philo		*philo;

	philo = (t_philo *) ph_philo;
	ft_set_last_meal_time(philo);
	while (get_status(philo) != DIED)
	{
		if (ft_eat(philo) != 0)
			break ;
		if (get_status(philo) == DIED)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (get_status(philo) == DIED)
			break ;
		if (ft_think(philo) != 0)
			break ;
		if (get_status(philo) == DIED)
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
	ph_nb_philo = ft_get_nb_philos(data); // write a mutexed getter ?
	data->start_time = ft_get_time();
	while (i < ph_nb_philo)
	{
		if (pthread_create(&data->philo_threads[i], NULL,
				&ft_routine, &data->philos[i]))
			return (1);
		i++;
	}
	/* if (ft_get_time() > ft_get_start_time(data))
	{ */
		if (pthread_create(&data->monitor, NULL,
			&ft_monitor_routine, data))
		return (1);
	/* } */
	return (0);
}

int	philosophers_problem(t_data *data)
{
	if (ft_init_data(data) != 0)
		return (1);
	ft_start_routine(data);
	ft_pthread_join(data);
	ft_free_data(data);
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
		if (philosophers_problem(&data) != 0)
		{
			ft_error(&data);
			return (1);
		}
	}
	return (0);
}

