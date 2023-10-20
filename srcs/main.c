/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:57:04 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/20 16:00:28 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//join threads, returns 1 if error
int	ft_pthread_join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo_threads[i], NULL))
			return (1);
		i++;
	}
	return (0);
}

void	*routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->mut_start_t);
	pthread_mutex_unlock(&philo->data->mut_start_t);
	while (are_we_done(philo->data) == 0)
	{
		if (ft_eat(philo) == 1)
			break ;
		if (are_we_done(philo->data) == 1)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		usleep((philo->data->time_to_eat > philo->data->time_to_sleep)
			* (philo->data->time_to_eat - philo->data->time_to_sleep) + 125);
		if (ft_think(philo) != 0)
			break ;
		if (are_we_done(philo->data) == 1)
			break ;
	}
	return (NULL);
}

//routine
void	*ft_routine(void *ph_philo)
{
	t_philo		*philo;

	philo = (t_philo *) ph_philo;
	if (philo->data->nb_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_mandatory_format(philo->data, philo->philo_id, 3, ft_get_time());
		while (are_we_done(philo->data) == 0)
			usleep(125);
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	if (philo->philo_id % 2 == 0)
		philo->prio = 0;
	else if (philo->philo_id != philo->data->nb_philo - 1)
		philo->prio = 1;
	else if (philo->data->nb_philo % 2 == 0)
		philo->prio = 1;
	else
		philo->prio = 0;
	routine(philo);
	return (NULL);
}

//pthread create and send to routine
int	ft_start_routine(t_data	*data)
{
	int			i;

	i = 0;
	pthread_mutex_lock(&data->mut_start_t);
	while (i < data->nb_philo)
	{
		ft_set_last_meal_time(&data->philos[i]);
		if (pthread_create(&data->philo_threads[i], NULL,
				&ft_routine, &data->philos[i]))
				return (1);
		i++;
	}
	data->start_time = ft_get_time();
	pthread_mutex_unlock(&data->mut_start_t);
	return (0);
}

int	philosophers_problem(t_data *data)
{
	if (ft_init_data(data) != 0)
		return (1);
	if (ft_start_routine(data) == 1 || ft_monitor(data) == 1)
			ft_pthread_join(data);
	ft_free_data(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (ft_init_args(argc, argv, &data) != 0)
		{
			printf("invalid arguments\n");
			return (1);
		}
		if (philosophers_problem(&data) != 0)
		{
			ft_error(&data);
			return (1);
		}
	}
	if (argc != 5 && argc != 6)
		printf("invalid arguments\n");
	return (0);
}

