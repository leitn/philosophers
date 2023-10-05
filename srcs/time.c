/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:53:06 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/05 17:41:55 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//Current time in ms !
long long	ft_get_time(t_data *data)
{
	struct timeval	time;
	long long		timestamp_in_ms;

	gettimeofday(&time, NULL);
	timestamp_in_ms = (long long)(time.tv_sec)*1000
		+ (long long)(time.tv_usec) / 1000;
	return (timestamp_in_ms - data->start_time);
}
