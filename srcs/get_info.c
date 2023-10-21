/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:34:21 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/21 12:34:08 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	ft_get_last_meal_time(t_philo *philo)
{
	long long	ph_time_last_meal;

	pthread_mutex_lock(&philo->mut_t_eating);
	ph_time_last_meal = philo->time_of_eating;
	pthread_mutex_unlock(&philo->mut_t_eating);
	return (ph_time_last_meal);
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
