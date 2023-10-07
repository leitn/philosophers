/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:45:33 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/07 13:59:06 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//MUTEX. Records corpse existence in t_data.
void	yell_omg_someone_just_died(t_data *data)
{
	pthread_mutex_lock(&data->mut_dead_man);
	if (data->dead_man_among_us == 0)
		data->dead_man_among_us = 1;
	pthread_mutex_unlock(&data->mut_dead_man);
}

//MUTEX. Changes philo status in t_philo.
void	set_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->mut_status);
	philo->status = status;
	pthread_mutex_unlock(&philo->mut_status);
}

//MUTEX. nb_meals++ in t_philo
void	set_nb_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_nb_meals);
	philo->nb_meals++;
	pthread_mutex_unlock(&philo->mut_nb_meals);
}

//MUTEX. sets finished_dinner at 1 in t_data
void	set_finished(t_data *data)
{
	pthread_mutex_lock(&data->mut_finished);
	if (data->finished_dinner == 0)
		data->finished_dinner = 1;
	pthread_mutex_unlock(&data->mut_finished);
}

//MUTEX. updates time of last meal and returns it
long long	ft_set_last_meal_time(t_philo *philo)
{
	long long	ph_time_last_meal;

	pthread_mutex_lock(&philo->mut_t_eating);
	philo->time_of_eating = ft_get_time();
	ph_time_last_meal = philo->time_of_eating;
	pthread_mutex_unlock(&philo->mut_t_eating);
	return (ph_time_last_meal);
}

// should I have a set last meal without returning it ?
