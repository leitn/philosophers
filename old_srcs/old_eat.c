/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:02:12 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 16:39:57 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//unlock mutex both forks.
void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->right_fork);
}

//Lock right fork mutex
int	take_right_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->right_fork) != 0)
	{
		print_mandatory_format(philo->data, philo->philo_id,
			"Slight issue with my left fork sorry\n");
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	print_mandatory_format(philo->data, philo->philo_id,
		"has taken their right fork\n");
	return (0);
}

//locks left fork mutex
int	take_left_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->left_fork) != 0)
	{
		print_mandatory_format(philo->data, philo->philo_id,
			"Slight issue with my left fork sorry\n");
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	print_mandatory_format(philo->data, philo->philo_id,
		"has taken their left fork\n");
	return (0);
}

int	ft_right_handed(t_philo *philo)
{
	if (take_right_fork(philo) != 0 || get_status(philo) == DIED)
		return (1);
	if (take_left_fork(philo) != 0 || get_status(philo) == DIED)
	{
		unlock_forks(philo);
		return (1);
	}
	return (0);
}

int	ft_left_handed(t_philo *philo)
{
	if (take_left_fork(philo) != 0 || get_status(philo) == DIED)
		return (1);
	if (take_right_fork(philo) != 0 || get_status(philo) == DIED)
	{
		unlock_forks(philo);
		return (1);
	}
	return (0);
}

//needs a function for only one philo case
int	ready_steady_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		if (ft_right_handed(philo) != 0
			|| get_status(philo) == DIED)
			return (1);
		return (0);
	}
	else
	{
		if (ft_left_handed(philo) != 0
			|| get_status(philo) == DIED)
			return (1);
		return (0);
	}
	return (0);
}

//WIP !
int	ft_eat(t_philo *philo)
{
	if (ready_steady_forks(philo) != 0)
		return (1);
	set_status(philo, EATING);
	print_mandatory_format(philo->data, philo->philo_id, " is eating.\n");
	ft_set_last_meal_time(philo);
	eat_usleep(ft_get_time_to_eat(philo));
	set_nb_meals(philo);
	unlock_forks(philo);
	return (0);
}

/*

	pthread_mutex_lock(&philo->data->mut_print);
	printf("%i's status is %u\n", philo->philo_id + 1, get_status(philo));
	pthread_mutex_unlock(&philo->data->mut_print);

*/