/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:18:01 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 14:09:48 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// incomplet !
void	ft_destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->philos[i].mut_status);
		pthread_mutex_destroy(&data->philos[i].mut_t_eating);
		pthread_mutex_destroy(&data->philos[i].mut_nb_meals);
		pthread_mutex_destroy(data->philos[i].right_fork);
		pthread_mutex_destroy(data->philos[i].left_fork);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mut_nb_philos);
	pthread_mutex_destroy(&data->mut_die_time);
	pthread_mutex_destroy(&data->mut_eat_time);
	pthread_mutex_destroy(&data->mut_sleep_t);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_start_t);
}

// WIP !
void	ft_free_data(t_data *data)
{
	ft_destroy_mutex(data);
	free(data->forks);
	free(data->philos);
	free(data->philo_threads);
}