/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:53:06 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 11:57:36 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// usleep for eat_time miliseconds
void	eat_usleep(long long eat_time)
{
	long long	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < eat_time)
		usleep(500);
}

// updates time of last meal w/ mutex
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
