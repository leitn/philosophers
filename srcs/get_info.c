/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:34:21 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/05 17:41:24 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

long long	ft_get_last_meal_time(t_philo *philo)
{

}
