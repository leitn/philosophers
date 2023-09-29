/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:04 by letnitan          #+#    #+#             */
/*   Updated: 2023/09/29 16:36:56 by letnitan         ###   ########.fr       */
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
int	ft_to_eat(t_data *data)
{
	do_nothing_but_make(data);
	return (0);
}

//WIP (obviously)
void	ft_routine(t_data *data)
{
	do_nothing_but_make(data);
}


/*
ft_routine brouillon

while (++i < nb_of_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL,
				&routine, &data->philos[i]))
			return (1);
	}


*/

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc <= 4 || argc > 6)
	{
		ft_printf("invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	ft_init_args(argc, argv, &data);
	ft_init_data(&data);
	ft_routine(&data);
	ft_free_data(&data);

	return (0);
}



/*-----------BROUILLON--------------*/

/*

/!\ FAIRE UN TRUC PROPRE POUR LES EXIT FAILURES
(fonction pour free, pour imprimer message d'erreur, etc)


*/
