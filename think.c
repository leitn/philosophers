/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:05:28 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/05 13:53:12 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//impro totale
int	ft_think(t_philo *philo)
{
	if (philo->status != THINKING && death_status(philo) != DIED)
	{
		philo->status = THINKING;
		usleep(100);
		return (1);
	}
	return (0);
}
