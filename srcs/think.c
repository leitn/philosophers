/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:05:28 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 12:25:11 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//Sets status, checks death, prints action monitoring. DOESNT SLEEP.
int	ft_think(t_philo *philo)
{
	set_status(philo, THINKING);
	if (death_status(philo) == DIED
		|| get_status(philo) == DIED)
		return (1);
	print_mandatory_format(philo->data, philo->philo_id, "is sleeping");
	return (0);
}

//should it sleep for a while ?
// check that using both death status and get status doesnt create a data race
