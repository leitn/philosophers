/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:04:55 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/07 14:09:42 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


// used in print_mandatory
int	are_we_done(t_data *data)
{
	int	i_see_dead_people;
	int	are_we_all_full;

	i_see_dead_people = ft_get_pulse(data);
	are_we_all_full = ft_get_completion(data);
	if (i_see_dead_people == 1)
		return(1); // there is a corpse
	if (are_we_all_full == 1)
		return(1); // everybody is full
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
