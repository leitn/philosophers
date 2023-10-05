/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:04:42 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/05 14:02:08 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//impro totale
int	ft_sleep(t_philo *philo)
{
	if (philo->status == SLEEPING)
	{
		if (pthread_mutex_lock(&philo->data->mut_sleep_t) == 0)
		{
			usleep(philo->data->time_to_sleep);
			philo->status = THINKING;
		}
		else if (pthread_mutex_lock(&philo->data->mut_sleep_t) != 0)
			ft_error(philo->data);
		pthread_mutex_unlock(&philo->data->mut_sleep_t);
	}
	return (0);
}
