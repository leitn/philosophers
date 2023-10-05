/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:02:12 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/05 16:11:32 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_right_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->mut_print) == 0)
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
		{
			printf("Slight issue with my right fork sorry");
			pthread_mutex_unlock(philo->right_fork);
			return (1);
		}
		printf("\nI am philosopher number %i\nI am taking my right fork !\n",
			philo->philo_id);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->data->mut_print);
		return (0);
	}
	else
		return (1);

}

int	take_left_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->mut_print) == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
		{
			printf("Slight issue with my left fork sorry");
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
		printf("\nI am philosopher number %i\nI am taking my left fork !\n",
			philo->philo_id);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->data->mut_print);
		return (0);
	}
	else
		return (1);
}

int	ft_right_handed(t_philo *philo)
{
	if (take_right_fork(philo) == 0)
	{
		if (take_left_fork(philo) != 0)
		{
			pthread_mutex_unlock(philo->right_fork);
			return (1);
		}
		return (0);
	}
	return (1);
}

int	ft_left_handed(t_philo *philo)
{
	if (take_left_fork(philo) == 0)
	{
		if (take_right_fork(philo) != 0)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
		return (0);
	}
	return (1);
}

//WIP (too long) !
int	ft_eat(t_philo *philo)
{
	if (death_status(philo) != DIED && philo->status != EATING)
	{
		if (philo->philo_id % 2 == 0)
		{
			if (ft_right_handed(philo) == 0)
			{
				philo->status = EATING;
				philo->time_of_eating = ft_get_time(philo->data);
				usleep(philo->data->time_to_eat);
				philo->nb_meals++;
				printf("Yummy");
				return (0);
			}
		}
		else
		{
			if (ft_left_handed(philo) == 0)
			{
				philo->status = EATING;
				philo->time_of_eating = ft_get_time(philo->data);
				usleep(philo->data->time_to_eat);
				philo->nb_meals++;
				printf("Yummy");
				return (0);
			}
		}
	}
	return (1);
}

/* Need a Drop Fork function ? */
