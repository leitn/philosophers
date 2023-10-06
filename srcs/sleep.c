/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:04:42 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 12:19:18 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//impro totale
int	ft_sleep(t_philo *philo)
{
	set_status(philo, SLEEPING);
	if (death_status(philo) == DIED
		|| get_status(philo) == DIED)
		return (1);
	sleep_usleep(ft_get_time_to_sleep(philo));
	return (0);
}
 //thread principal peut changer status donc retester get_status en plus de death status.
 // verifier que checker les deux ne cree pas un data race ? normalement ils unlock bien tous les mutex qu'ils utilisent mais sait-on jamais
