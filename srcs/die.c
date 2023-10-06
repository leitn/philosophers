/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:04:55 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 15:02:43 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

//impro totale. Calculates and sets status if died
int	death_status(t_philo *philo)
{
	long long	death_time;

	death_time = ft_get_time_to_die(philo);
	if (ft_get_time() - ft_get_last_meal_time(philo) >= death_time)
	{
		set_status(philo, DIED);
		return (3);
	}
	return (0);
}
