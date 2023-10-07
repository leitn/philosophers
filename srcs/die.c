/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:04:55 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/07 13:49:36 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	yell_omg_someone_just_died(t_data *data)
{
	pthread_mutex_lock(&data->mut_dead_man);
	if (data->dead_man_among_us == 0)
		data->dead_man_among_us = 1;
	pthread_mutex_unlock(&data->mut_dead_man);
}

// used in print_mandatory
int	are_we_done(t_data *data)
{

	return (0); // All good
}


//calls death_status for i < nb_philo (main thread)
int	is_someone_dead(t_data *data)
{
	int	i;
	int	nb;

	i = 0;
	nb = ft_get_nb_philos(data);
	while (i < nb)
	{
		if (death_status(&data->philos[i]) == 3)
			return (1);
		i++;
	}
	return (0);
}

//Calculates and sets status if died
int	death_status(t_philo *philo)
{
	long long	death_time;
	t_data		*data;

	data = philo->data;
	death_time = ft_get_time_to_die(philo);
	if (ft_get_time() - ft_get_last_meal_time(philo) >= death_time)
	{
		set_status(philo, DIED);
		return (3);
	}
	return (0);
}
