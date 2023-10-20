/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:53:06 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/20 19:05:12 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


// usleep for eat_time miliseconds
int	eat_usleep(t_philo *philo, long long eat_time, long long s_time)
{
	while ((ft_get_time() - s_time) < eat_time)
	{
		if (are_we_done(philo->data) == 1)
			return (1);
		usleep(100);
	}
	return (0);
}

// usleep for sleep_time miliseconds
int	sleep_usleep(t_philo *philo, long long sleep_time, long long start)
{
	while ((ft_get_time() - start) < sleep_time)
	{
		if (are_we_done(philo->data) == 1)
			return (1);
		usleep(100);
	}
	return (0);
}

// MUTEX. updates time of last meal in structure
void	ft_time_of_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->mut_t_eating);
	philo->time_of_eating = ft_get_time();
	pthread_mutex_unlock(&philo->mut_t_eating);
}

//Current time in ms
long long	ft_get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}


/*

Implementer un ft_usleep plus precis ?
*/
