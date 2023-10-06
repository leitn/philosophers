/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:04:55 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 12:03:29 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//calls death_status for i < nb_philo (main thread)
int	is_someone_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (death_status(&data->philos[i]) == 3)
		{
			print_with_mutex("\nis someone dead returned 1\n"); //delete later
			return (1);
		}
		i++;
	}
	print_with_mutex("\nis_someone_dead returned 0"); //delete later
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
		print_with_mutex("\nI'm dead\n", philo->data);
		return (3);
	}
	print_with_mutex("\nI'm alive\n", philo->data);
	return (0);
}
