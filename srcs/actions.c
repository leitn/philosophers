/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:06:02 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/20 14:44:05 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	invert_prio(t_philo *philo)
{
	if (philo->prio == 0)
		return (1);
	return (0);
}

int	check_if_prio(t_philo *philo)
{
	if ((philo->prio) == 0)
	{
		print_mandatory_format(philo->data, philo->philo_id, 2);
		if (eat_usleep(philo, philo->data->time_to_eat) == 1)
			return (1);
		philo->prio = invert_prio(philo);
		return (1);
	}
	return (0);
}

//checks for death, prints action and sleeps for sleep_time.
int	ft_sleep(t_philo *philo)
{
	if (print_mandatory_format(philo->data, philo->philo_id, 1) == 1)
		return(1);
	if (are_we_done(philo->data) == 1)
		return (1);
	if ((sleep_usleep(philo, philo->data->time_to_sleep)) == 1)
		return (1);
	return (0);
}

int	think_different(long long start, t_philo *philo)
{
	while (ft_get_time() - start < 3)
	{
		if (are_we_done(philo->data) == 1)
			return (1) ;
		usleep(500);
	}
	return (0);
}
//checks death, prints action monitoring.
int	ft_think(t_philo *philo)
{
	int			nb_philo;
	int			t_to_eat;
	int			t_to_sleep;
	long long	start;

	nb_philo = philo->data->nb_philo;
	t_to_eat = philo->data->time_to_eat;
	t_to_sleep = philo->data->time_to_sleep;
	start = ft_get_time();
	if (are_we_done(philo->data) == 1)
		return (1);
	if (print_mandatory_format(philo->data, philo->philo_id, 2))
		return (1);
	if (nb_philo % 2 == 0 || t_to_sleep > t_to_eat)
		return (think_different(start, philo));
	while (ft_get_time() - start < t_to_eat * 2- t_to_sleep)
		usleep(25);
	return (0);
}

/* 	while (ft_get_time() - start < t_to_eat * 2- t_to_sleep)
		usleep(25); */
