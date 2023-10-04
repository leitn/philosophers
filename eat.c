/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:02:12 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/04 19:40:45 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_right_handed(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->mut_print) == 0)
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
		{
			printf("Slight issue with my right fork sorry");
			pthread_mutex_unlock(philo->right_fork);
			return (1);
		}
		printf("\nI am philosopher number %i\nI am taking my right fork first!\n", philo->philo_id);
		if (pthread_mutex_lock(philo->left_fork) == 0)
			printf("I am now taking the left one !\n\n");
		else
		{
			printf(":( my left fork is taken...");
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&philo->data->mut_print);
		return (0);
	}
	else
		return (1);

}

int	ft_left_handed(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->mut_print) == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
		{
			printf("Slight issue with my left fork sorry");
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
		printf("\nI am philosopher number %i\nI am taking my left fork first!\n", philo->philo_id);
		if (pthread_mutex_lock(philo->right_fork) == 0)
			printf("I am now taking the right one !\n\n");
		else
		{
			printf(":( my right fork is taken...");
			pthread_mutex_unlock(philo->right_fork);
			exit(1);
		}
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->data->mut_print);
		return (0);
	}
	else
		return (1);
}

//WIP (obviously)
int	ft_to_eat(t_data *data)
{
	do_nothing_but_make(data);
	return (0);
}
