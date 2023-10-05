/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:04:42 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/05 12:37:41 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//impro totale
int	ft_sleep(t_philo *philo)
{
	if (philo->status == 0)
	{
		usleep(philo->data->time_to_sleep);
		philo->status = 2;
	}
	return (0);
}
