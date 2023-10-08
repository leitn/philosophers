/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:13:18 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/08 20:14:04 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long	ft_get_nb_philos(t_data *data)
{
	long	ph_nb;

	pthread_mutex_lock(&data->mut_nb_philos);
	ph_nb = data->nb_philo;
	pthread_mutex_unlock(&data->mut_nb_philos);
	return (ph_nb);
}

long long	ft_get_start_time(t_data *data)
{
	long long	ph_start_time;

	pthread_mutex_lock(&data->mut_start_t);
	ph_start_time = data->start_time;
	pthread_mutex_unlock(&data->mut_start_t);
	return (ph_start_time);
}

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