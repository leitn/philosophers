/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:04 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/04 18:11:45 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// To make while having incomplete functions
void	do_nothing_but_make(t_data *data)
{
	int	memento_mori;

	memento_mori = data->time_to_die;
}

//WIP (obviously)
void	*ft_routine(void *ph_philo)
{
	t_philo	*philo;

	philo = (t_philo *) ph_philo;
	pthread_mutex_lock(&philo->data->mut_print);
	printf("\nThis is a test\n");
	pthread_mutex_unlock(&philo->data->mut_print);
	return (NULL);
}

//pthread create and send to routine
int	ft_start_routine(t_data	*data)
{
	int	i;

	i = 0;
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



/*-----------BROUILLON--------------*/

/*

/!\ FAIRE UN TRUC PROPRE POUR LES EXIT FAILURES
(fonction pour free, pour imprimer message d'erreur, etc)


*/
