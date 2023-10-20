/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:34:21 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/20 12:42:06 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//checks time of last meal in struct and returns it
long long	ft_get_last_meal_time(t_philo *philo)
{
	long long	ph_time_last_meal;

	pthread_mutex_lock(&philo->mut_t_eating);
	ph_time_last_meal = philo->time_of_eating;
	pthread_mutex_unlock(&philo->mut_t_eating);
	return (ph_time_last_meal);
}

//MUTEX. checks and return time_to_eat parameter.
long long	ft_get_time_to_eat(t_philo *philo)
{
	long long	ph_time_to_eat;

	pthread_mutex_lock(&philo->data->mut_eat_time);
	ph_time_to_eat = philo->data->time_to_eat;
	pthread_mutex_unlock(&philo->data->mut_eat_time);
	return (ph_time_to_eat);
}

//MUTEX. checks and return time_to_die parameter.
long long	ft_get_time_to_die(t_philo *philo)
{
	long long	ph_time_to_die;

	pthread_mutex_lock(&philo->data->mut_die_time);
	ph_time_to_die = philo->data->time_to_die;
	pthread_mutex_unlock(&philo->data->mut_die_time);
	return (ph_time_to_die);
}

//MUTEX. checks and return time_to_sleep parameter.
long long	ft_get_time_to_sleep(t_philo *philo)
{
	long long	ph_time_to_sleep;

	pthread_mutex_lock(&philo->data->mut_sleep_t);
	ph_time_to_sleep = philo->data->time_to_sleep;
	pthread_mutex_unlock(&philo->data->mut_sleep_t);
	return (ph_time_to_sleep);
}
