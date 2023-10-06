/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:02:12 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 11:44:17 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	take_right_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->right_fork) != 0)
	{
		print_with_mutex("Slight issue with my right fork sorry", philo->data);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	print_mandatory_format(philo->data, philo->philo_id,
		"has taken their right fork");
	pthread_mutex_unlock(philo->right_fork);
	return (0);
}

int	take_left_fork(t_philo *philo)
{
	if (pthread_mutex_lock(philo->left_fork) != 0)
	{
		print_with_mutex("Slight issue with my left fork sorry", philo->data);
		return (1);
	}
	print_mandatory_format(philo->data, philo->philo_id,
		"has taken their left fork");
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

int	ft_right_handed(t_philo *philo)
{
	if (take_right_fork(philo) != 0)
		return (1);
	if (take_left_fork(philo) != 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	return (0);
}

int	ft_left_handed(t_philo *philo)
{
	if (take_left_fork(philo) == 0)
		return (1);
	if (take_right_fork(philo) != 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}

int	ready_steady_forks(t_philo *philo)
{
	if (philo->philo_id == 1)
	{
		print_with_mutex("Only one philo not handled yet", philo->data);
		return (1);
	}
	if (philo->philo_id % 2 == 0)
	{
		if (ft_right_handed(philo) != 0)
			return (1);
		philo->nb_meals++;
		print_with_mutex("Yummy", philo->data);
		return (0);
	}
	else
	{
		if (ft_left_handed(philo) != 0)
			return (1);
		philo->nb_meals++;
		print_with_mutex("Yummy", philo->data);
		return (0);
	}
	return (0);
}

//WIP !
int	ft_eat(t_philo *philo)
{
	if (ready_steady_forks(philo) != 0)
		return (1);
	return (0);
}
