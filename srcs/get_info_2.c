/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:13:18 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/20 17:49:04 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


int	ft_get_nb_max_meals(t_data *data)
{
	int	max_meals;

	pthread_mutex_lock(&data->mut_max_meals);
	max_meals = data->nb_max_meals;
	pthread_mutex_unlock(&data->mut_max_meals);
	return (max_meals);
}

int	ft_get_pulse(t_data *data)
{
	int	pulse;

	pthread_mutex_lock(&data->mut_dead_man);
	pulse = data->dead_man_among_us;
	pthread_mutex_unlock(&data->mut_dead_man);
	return (pulse);
}

int	ft_get_completion(t_data *data)
{
	int	completion_status;

	pthread_mutex_lock(&data->mut_finished);
	completion_status = data->finished_dinner;
	pthread_mutex_unlock(&data->mut_finished);
	return (completion_status);
}
