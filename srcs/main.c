/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:04 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 12:37:14 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//join threads, returns 1 if error
int	ft_pthread_join(t_data *data)
{
	int	i;
	int	nb;

	i = 0;
	nb = data->nb_philo; //write a getter ?
	while (i < nb)
	{
		if (pthread_join(data->philo_threads[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

//routine
void	*ft_routine(void *ph_philo)
{
	t_philo		*philo;

	philo = (t_philo *) ph_philo;
	philo->time_of_eating = ft_get_time() - philo->data->start_time;
	ft_get_last_meal_time(philo);
	while (get_status(philo) != DIED)
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
	ph_nb_philo = data->nb_philo; // write a mutexed getter ?
	data->start_time = ft_get_time();
	while (i < ph_nb_philo)
	{
		if (pthread_create(&data->philo_threads[i], NULL,
				&ft_routine, &data->philos[i]))
		{
			ft_pthread_join(data); // ca va creer une erreur je join tous les threads c'est pas sur qu'ils existent tous
			return (1);
		}
		if (is_someone_dead(data) == 1) // TO DO : better monitoring
		{
			print_with_mutex("Someone died. RIP\n", data);
			return (1);
		}
		i++;
	}
	return (0);
}

int	philosophers_problem(t_data *data)
{
	if (ft_start_routine(data))
		return (1);
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
		if (ft_init_data(&data) != 0)
		{
			ft_error(&data);
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

// in the main : instead of init args,
// have a ft_parsing and then init in init_data with
// a simple atoi
// write a a getter for nb_philos ?
