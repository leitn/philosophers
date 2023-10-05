/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:04:55 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/05 18:05:41 by letnitan         ###   ########.fr       */
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
	printf("\n in death_status, DEATH TIME = %lli\n", death_time);
	printf("\n in death_status,FT_GET_TIME = %lli\n", ft_get_time());
	printf("\n in death_status,GET LAST MEAL TIME = %lli\n",
		ft_get_last_meal_time(philo));
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
