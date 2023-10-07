/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:40:50 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/07 11:55:29 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	finished_eating(t_data *data)
{
	int	i;
	int	max_meals;
	int	nb_philo

	i = 0;
	max_meals = ft_get_nb_max_meals(data);
	nb_philos = ft_get_nb_philos(data);
	if (max_meals >= 0)
	{
		while (i < nb_philos)
		{
			if (data->philos[i].nb_meals < max_meals)
				break ;
			set_status(data->philo[i], FULL);
			i++;
		}
		if (i == nb_philos)
		{
			set_status()
		}
	}
	return (0); //they all finished eating
}

int	is_that_one_alive(t_philo *philo)
{
	long long	now;
	long long	last_meal_time;
	long long	fatal_starvation_time;

	last_meal_time = ft_get_last_meal_time(philo);
	now = ft_get_time();
	fatal_starvation_time = ft_get_time_to_die(philo);
	if (now - last_meal_time >= fatal_stavation_time)
		return (1); // aka No, that one is not alive
	return (0); // Yes, all good
}

int	valar_morghulis(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (is_that_one_alive(data->philos[i]) != 0)
		{
			set_status(philos[i], DIED);
			print_mandatory_format(data, philo[i]->id, "is dead.");
			return (1); // dead and buried
		}
		i++;
	}
	return (0); // no one died
}

void	ft_monitor(t_data *data)
{
	int	i;

	usleep(125);
	while (valar_morghulis(data) && !finished_eating(data)) //continue while all good
		usleep(500);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo_threads[i], NULL)
		i++;
	}
}
