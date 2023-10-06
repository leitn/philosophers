/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:45:33 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 12:11:06 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//MUTEX. Changes philo status.
void	set_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->mut_status);
	if (philo->status != DIED)
		philo->status = status;
	pthread_mutex_unlock(&philo->mut_status);
}
