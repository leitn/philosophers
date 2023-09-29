/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:15:01 by letnitan          #+#    #+#             */
/*   Updated: 2023/09/29 16:40:28 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//WIP (obviously)
int	ft_init_forks(t_data *data)
{
	do_nothing_but_make(data);
	return (0);
}

//WIP (obviously)
void	ft_init_data(t_data *data)
{
	if (ft_init_forks(data))
		exit(EXIT_FAILURE);
	data->forks = malloc(data->nb_of_philo * sizeof(pthread_mutex_t));
	if (data->forks == NULL)
		exit(EXIT_FAILURE);
}

/*-----------------------BROUILLON---------------------*/

/* ft_init_data */

/*
init_forks
init autres mutex


*/
