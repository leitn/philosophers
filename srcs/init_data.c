/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:15:01 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/05 17:55:24 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//malloc data.philo_threads.
int	ft_init_philos_threads(t_data *data)
{
	data->philo_threads = malloc(data->nb_philo * sizeof(pthread_t));
	if (data->philo_threads == NULL)
		return (1);
	return (0);
}

//malloc data.philos && fills it. Too long.
int	ft_init_philos(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	data->philos = malloc(data->nb_philo * sizeof(t_philo));
	if (data->philos == NULL)
		return (1);
	philo = data->philos;
	while (i < (data->nb_philo - 1))
	{
		philo[i].data = data;
		philo[i].philo_id = i;
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = &data->forks[i + 1];
		philo[i].time_of_eating = philo->data->start_time;
		philo[i].nb_meals = 0;
		philo[i].status = NOTHING;
		pthread_mutex_init(&philo[i].mut_status, NULL);
		pthread_mutex_init(&philo[i].mut_t_eating, NULL);
		i++;
	}
	if (i == (data->nb_philo - 1))
	{
		philo[i].data = data;
		philo[i].philo_id = i;
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = &data->forks[0];
		philo[i].time_of_eating = philo->data->start_time;
		philo[i].nb_meals = 0;
		pthread_mutex_init(&philo[i].mut_status, NULL);
		pthread_mutex_init(&philo[i].mut_t_eating, NULL);
		philo[i].status = NOTHING;
	}
	philo = data->philos;
	return (0);
}

//malloc data.forks && init its mutexes
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


//init structures
int	ft_init_data(t_data *data)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	data->start_time = (long long)(tv.tv_sec)*1000
		+ (long long)(tv.tv_usec) / 1000;
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

