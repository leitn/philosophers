/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:04 by letnitan          #+#    #+#             */
/*   Updated: 2023/09/29 16:00:22 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	do_nothing_but_make(t_data *data)
{
	int	memento_mori;

	memento_mori = data->time_to_die;
}


int	ft_to_eat(t_data *data)
{
	do_nothing_but_make(data);
	return (0);
}


void	*thread_routine(void *data)
{
	do_nothing_but_make(data);
	return (0);
}

void	ft_create_threads(int i, t_data *data)
{
	int	a;

	a = i;
	do_nothing_but_make(data);
}


int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc <= 4 || argc > 6)
	{
		ft_printf("invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	data.forks = malloc(data.nb_of_philo * sizeof(pthread_mutex_t));
	ft_init_args(argc, argv, &data);
	free(data.forks);
	return (0);
}

