/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:40:50 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/07 14:37:25 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	finished_eating(t_data *data)
{
	int	i;
	int	max_meals;
	int	nb_philo;

	i = 0;
	max_meals = ft_get_nb_max_meals(data);
	nb_philo = ft_get_nb_philos(data);
	if (max_meals >= 0)
	{
		while (i < nb_philo)
		{
			if (data->philos[i].nb_meals < max_meals)
				break ;
			set_status(&data->philos[i], FULL);
			i++;
		}
		if (i == nb_philo)
		{
			set_finished(data);
			return (1); //Yes, they all finished eating
		}
	}
	return (0); //No, they did not finish eating
}

int	is_that_one_dead(t_philo *philo)
{
	long long	now;
	long long	last_meal_time;
	long long	fatal_starvation_time;

	last_meal_time = ft_get_last_meal_time(philo);
	now = ft_get_time();
	fatal_starvation_time = ft_get_time_to_die(philo);
	if (now - last_meal_time >= fatal_starvation_time)
		return (1); // aka Yes, that one is dead
	return (0); // No, all good
}

int	valar_morghulis(t_data *data)
{
	int	i;
	int	nb;

	i = 0;
	nb = ft_get_nb_philos(data);
	while (i < nb)
	{
		if (is_that_one_dead(&data->philos[i]) == 1)
		{
			set_status(&data->philos[i], DIED);
			yell_omg_someone_just_died(data);
			print_mandatory_format(data, data->philos[i].philo_id, 5);
			return (1); // someone died and it has been recorded in data
		}
		i++;
	}
	return (0); // no one died
}

void	ft_monitor(t_data *data)
{
	int	i;

	usleep(125);
	while (valar_morghulis(data) == 0 && finished_eating(data) == 0) //continue while all good
		usleep(500);
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philo_threads[i], NULL);
		i++;
	}
}
