/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:34:21 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/07 14:08:20 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//checks status in structure, doesnt set it, uses mutex
t_status	get_status(t_philo *philo)
{
	t_status	ph_status;

	pthread_mutex_lock(&philo->mut_status);
	ph_status = philo->status;
	pthread_mutex_unlock(&philo->mut_status);
	return (ph_status);
}

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
