/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 12:43:28 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/21 12:44:06 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	take_right_fork(t_philo *philo)
{
	if (are_we_done(philo->data) == 1
		|| pthread_mutex_lock(philo->right_fork) != 0)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	if (are_we_done(philo->data) == 1
		|| print_mandatory_format(philo->data, philo->philo_id,
			4, ft_get_time()) == 1)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	return (0);
}

int	take_left_fork(t_philo *philo)
{
	if (are_we_done(philo->data) == 1
		|| pthread_mutex_lock(philo->left_fork) != 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	if (are_we_done(philo->data) == 1
		|| print_mandatory_format(philo->data, philo->philo_id,
			3, ft_get_time()) == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}
