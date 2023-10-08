/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:36:32 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/08 16:46:44 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_if_prio(t_philo *philo)
{
	if ((philo->prio) == 0)
	{
		print_mandatory_format(philo->data, philo->philo_id, 2);
		if (eat_usleep(philo, ft_get_time_to_eat(philo)) == 1)
			return (1);
		philo->prio = invert_prio(philo);
		return (1);
	}
	return (0);
}

//Sets status, checks for death, prints action and sleeps for sleep_time.
int	ft_sleep(t_philo *philo)
{
	set_status(philo, SLEEPING);
	if (are_we_done(philo->data) == 1)
		return (1);
	if (print_mandatory_format(philo->data, philo->philo_id, 1) == 1)
		return(1);
	if ((sleep_usleep(philo, ft_get_time_to_sleep(philo))) == 1)
		return (1);
	return (0);
}
//Sets status, checks death, prints action monitoring. DOESNT SLEEP.
int	ft_think(t_philo *philo)
{
	int			nb_philo;
	int			t_to_eat;
	int			t_to_sleep;
	long long	start;

	nb_philo = ft_get_nb_philos(philo->data);
	t_to_eat = ft_get_time_to_eat(philo);
	t_to_sleep = ft_get_time_to_sleep(philo);
	start = ft_get_time();
	set_status(philo, THINKING);
	if (are_we_done(philo->data) == 1)
		return (1);
	if (print_mandatory_format(philo->data, philo->philo_id, 2))
		return (1);

	if (nb_philo % 2 == 0 || t_to_sleep > t_to_eat)
	{
		while (ft_get_time() - start < 3)
		{
			if (are_we_done(philo->data) == 1)
				return (0);
			usleep(500);
		}
		return (0);
	}
	while (ft_get_time() - start < t_to_eat * 2- t_to_sleep)
		usleep(25);
	return (0);
}
// incomplet !
void	ft_destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->philos[i].mut_status);
		pthread_mutex_destroy(&data->philos[i].mut_t_eating);
		pthread_mutex_destroy(&data->philos[i].mut_nb_meals);
		pthread_mutex_destroy(data->philos[i].right_fork);
		pthread_mutex_destroy(data->philos[i].left_fork);
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mut_nb_philos);
	pthread_mutex_destroy(&data->mut_start_t);
	pthread_mutex_destroy(&data->mut_die_time);
	pthread_mutex_destroy(&data->mut_eat_time);
	pthread_mutex_destroy(&data->mut_sleep_t);
	pthread_mutex_destroy(&data->mut_max_meals);
	pthread_mutex_destroy(&data->mut_finished);
	pthread_mutex_destroy(&data->mut_dead_man);
	pthread_mutex_destroy(&data->mut_print);
}

// WIP !
void	ft_free_data(t_data *data)
{
	ft_destroy_mutex(data);
	free(data->forks);
	free(data->philos);
	free(data->philo_threads);
}
