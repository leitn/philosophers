/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:02:12 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/21 12:43:43 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_right_handed(t_philo *philo)
{
	if (are_we_done(philo->data) == 1 || take_right_fork(philo) != 0)
		return (1);
	if (are_we_done(philo->data) == 1 || take_left_fork(philo) != 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	return (0);
}

int	ft_left_handed(t_philo *philo)
{
	if (are_we_done(philo->data) == 1 || take_left_fork(philo) != 0)
		return (1);
	if (are_we_done(philo->data) == 1 || take_right_fork(philo) != 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}

int	ready_steady_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		if (are_we_done(philo->data) == 1 || ft_right_handed(philo) != 0)
			return (1);
		return (0);
	}
	else
	{
		if (are_we_done(philo->data) == 1 || ft_left_handed(philo) != 0)
			return (1);
		return (0);
	}
	return (0);
}

void	unlock_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
}

int	ft_eat(t_philo *philo)
{
	check_if_prio(philo, ft_get_time());
	if (ready_steady_forks(philo) == 1)
		return (1);
	print_mandatory_format(philo->data, philo->philo_id, 0, ft_get_time());
	ft_set_last_meal_time(philo);
	set_nb_meals(philo);
	if ((eat_usleep(philo, philo->data->time_to_eat, ft_get_time())) == 1)
	{
		unlock_forks(philo);
		return (1);
	}
	if (are_we_done(philo->data) == 1)
	{
		unlock_forks(philo);
		return (1);
	}
	unlock_forks(philo);
	return (0);
}
