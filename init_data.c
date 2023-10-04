/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:15:01 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/04 15:48:47 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//WIP (obviously)
int	ft_init_philos_threads(t_data *data)
{
	data->philo_threads = malloc(data->nb_philo * sizeof(pthread_t));
	if (data->philo_threads == NULL)
		return (1);
	return (0);
}

//WIP (obviously)
int	ft_init_philos(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	data->philos = malloc(data->nb_philo * sizeof(t_philo));
	if (data->philos == NULL)
		return (1);
	while (i < data->nb_philo)
	{
		philo[i].data = data;
		philo[i].philo_id = i;
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = &data->forks[i + 1];
		philo[i].time_of_eating = 0;
		philo[i].dead = 0;
		i++;
	}
	philo = data->philos;
	return (0);
}

//WIP (obviously)
int	ft_init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(data->nb_philo * sizeof(pthread_mutex_t));
	if (data->forks == NULL)
		return (1);
	while (i < data->nb_philo)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
	return (0);
}


//WIP (obviously)
int	ft_init_data(t_data *data)
{
	if (ft_init_forks(data) != 0)
		return (1);
	if (ft_init_philos(data) != 0)
		return (1);
	if (ft_init_philos_threads(data) != 0)
		return (1);
	pthread_mutex_init(&data->mut_eat_time, NULL);
	pthread_mutex_init(&data->mut_sleep_t, NULL);
	pthread_mutex_init(&data->mut_die_time, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_nb_philos, NULL);
	pthread_mutex_init(&data->mut_start_t, NULL);
	return (0);

}

