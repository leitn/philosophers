/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:04:55 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 11:05:35 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	is_someone_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (death_status(&data->philos[i]) == 3)
		{
			printf("\nis someone dead returned 1\n");
			return (1);
		}
		i++;
	}
	printf("\nis_someone_dead returned 0");
	return (0);
}

//impro totale, WIP
int	death_status(t_philo *philo)
{
	long long	death_time;

	death_time = (ft_get_time() - philo->data->start_time)
		- ft_get_last_meal_time(philo);
	if (death_time >= philo->data->time_to_die)
	{
		if (pthread_mutex_lock(&philo->mut_status) == 0)
		{
			philo->status = DIED;
			pthread_mutex_unlock(&philo->mut_status);
		}
		printf("\nI'm dead\n");
		return (3);
	}
	printf("\nI'm alive\n");
	return (0);
}
