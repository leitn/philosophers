/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:05:28 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/05 16:42:58 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//impro totale
int	ft_think(t_philo *philo)
{
	if (philo->status != THINKING && death_status(philo) != DIED)
	{

		if (pthread_mutex_lock(&philo->mut_status) == 0)
		{
			philo->status = THINKING;
			pthread_mutex_unlock(&philo->mut_status);
		}
		usleep(100); // why did I even write that
		return (1);
	}
	return (0);
}
