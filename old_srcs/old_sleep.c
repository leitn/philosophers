/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:04:42 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 15:50:49 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//Sets status, checks for death, prints action and sleeps for sleep_time.
int	ft_sleep(t_philo *philo)
{
	set_status(philo, SLEEPING);
	if (get_status(philo) == DIED)
		return (1);
	print_mandatory_format(philo->data, philo->philo_id, "is sleeping\n");
	sleep_usleep(ft_get_time_to_sleep(philo));
	return (0);
}
 //thread principal peut changer status donc retester get_status en plus de death status.
 // verifier que checker les deux ne cree pas un data race ? normalement ils unlock bien tous les mutex qu'ils utilisent mais sait-on jamais
