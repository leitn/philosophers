/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:36:32 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/20 12:31:16 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_get_nb_meals(t_philo *philo)
{
	int	ph_nb_meals;

	pthread_mutex_lock(&philo->mut_nb_meals);
	ph_nb_meals = philo->nb_meals;
	pthread_mutex_unlock(&philo->mut_nb_meals);
	return (ph_nb_meals);
}


//prints error and FREES data
void	ft_error(t_data	*data)
{
	pthread_mutex_lock(&data->mut_print);
	printf("\nERROR\n");
	pthread_mutex_unlock(&data->mut_print);
	ft_free_data(data);
}

int	print_mandatory_format(t_data *data, int id, int option)
{
	static char	*lookup[6] = {
		"%lld %d is eating\n",
		"%lld %d is sleeping\n",
		"%lld %d is thinking\n",
		"%lld %d has taken a fork\n",
		"%lld %d has taken a fork\n",
		"%lld %d died\n"};
	long long	time;
	long long	ph_start_time;

	ph_start_time = ft_get_start_time(data);
	time = ft_get_time() - ph_start_time;
	pthread_mutex_lock(&data->mut_print);
	if (option != 5 && are_we_done(data) == 1)
		return (pthread_mutex_unlock(&data->mut_print), 1);
	printf(lookup[option], time, id + 1);
	pthread_mutex_unlock(&data->mut_print);
	return (0);
}

void	ft_destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->philos[i].mut_status);
		pthread_mutex_destroy(&data->philos[i].mut_t_eating);
		pthread_mutex_destroy(&data->philos[i].mut_nb_meals);
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

void	ft_free_data(t_data *data)
{
	ft_destroy_mutex(data);
	free(data->forks);
	free(data->philos);
	free(data->philo_threads);
}
