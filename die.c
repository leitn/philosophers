/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:04:55 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/05 16:37:54 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_status	get_status(t_philo *philo)
{
	t_status	ph_status;

	if (pthread_mutex_lock(&philo->mut_status) == 0)
	{
		ph_status = philo->status;
		pthread_mutex_unlock(&philo->mut_status);
		return (ph_status);
	}
	else
		ph_status = NOTHING;
	return (ph_status);
}

int	is_someone_dead(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (death_status(&data->philos[i]) == 3)
		{
			printf("\nis someone dead returned 1");
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

	death_time = ft_get_time(philo->data) - philo->time_of_eating;
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
