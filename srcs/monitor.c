/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:40:50 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 16:15:57 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	attention_everyone(t_data *data)
{
	int	i;
	int	ph_nb;

	i = 0;
	ph_nb = ft_get_nb_philos(data);
	while (i < ph_nb)
	{
		set_status(&data->philos[i], DIED);
		i++;
	}
}

void	*ft_monitor_routine(void *data)
{
	t_data	*ph_data;
	t_philo	*ph_philo;
	int		i;
	int		ph_nb;

	ph_data = (t_data *)data;
	ph_philo = ph_data->philos;
	ph_nb = ft_get_nb_philos(ph_data);
	i = 0;
	while (i < ph_nb)
	{
		if (death_status(&ph_philo[i]) == DIED)
		{
			print_mandatory_format(ph_data, ph_philo->philo_id,
				" is dead. \n");
			attention_everyone(data);
			break ;
		}
		if (i == ph_nb - 1)
			i = 0;
		i++;
		usleep(500);
	}
	return (NULL);
}
