/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:45:33 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 15:01:59 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//MUTEX. Changes philo status.
void	set_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->mut_status);
	philo->status = status;
	pthread_mutex_unlock(&philo->mut_status);
}

void	set_nb_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_nb_meals);
	philo->nb_meals++;
	pthread_mutex_unlock(&philo->mut_nb_meals);
}

//updates time of last meal and returns it
long long	ft_set_last_meal_time(t_philo *philo)
{
	long long	ph_time_last_meal;

	pthread_mutex_lock(&philo->mut_t_eating);
	philo->time_of_eating = ft_get_time();
	ph_time_last_meal = philo->time_of_eating;
	pthread_mutex_unlock(&philo->mut_t_eating);
	return (ph_time_last_meal);
}
