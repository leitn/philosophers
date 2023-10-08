/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:21:03 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/08 19:49:30 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//atoi
int	ft_atoi(char *str)
{
	int		count;
	int		result;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while (str[count] != '\0')
	{
		if (str[count] == '-')
			return (-1);
		if (str[count] < '0' || str[count] > '9')
			return (-1);
		if(str[count] >= '0' && str[count] <= '9')
		{
			if (result > result * 10 + str[count] - 48)
				return (-1);
			result = result * 10 + (str[count] - '0');
			count++;
		}
	}
	return (result * sign);
}

long	ft_atol(char *str)
{
	int		count;
	long	result;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while (str[count] != '\0')
	{
		if (str[count] == '-')
			return (-1);
		if (str[count] < '0' || str[count] > '9')
			return (-1);
		if(str[count] >= '0' && str[count] <= '9')
		{
			if (result > result * 10 + str[count] - 48)
				return (-1);
			result = result * 10 + (str[count] - '0');
			count++;
		}
	}
	return (result * sign);
}

long long	ft_atoll(char *str)
{
	int			count;
	long long	result;
	int			sign;

	count = 0;
	result = 0;
	sign = 1;
	while (str[count] != '\0')
	{
		if (str[count] == '-')
			return (-1);
		if (str[count] < '0' || str[count] > '9')
			return (-1);
		if(str[count] >= '0' && str[count] <= '9')
		{
			if (result > result * 10 + str[count] - 48)
				return (-1);
			result = result * 10 + (str[count] - '0');
			count++;
		}
	}
	return (result * sign);
}

// delete it ?
//prints error and FREES data
void	ft_error(t_data	*data)
{
	print_with_mutex("ERROR", data);
	ft_free_data(data);
}

//MUTEX. Prints a simple str. Used for debugging
void	print_with_mutex(char *str, t_data *data)
{
	pthread_mutex_lock(&data->mut_print);
	printf("\n%s\n", str);
	pthread_mutex_unlock(&data->mut_print);
}

//MUTEX. Prints action monitoring message in "time id str" format.
// void	print_mandatory_format(t_data *data, int id, char *str)
// {
// 	long long	time;
// 	long long	ph_start_t;

// 	ph_start_t = data->start_time;
// 	time = ft_get_time() - ph_start_t;
// 	pthread_mutex_lock(&data->mut_print);
// 	printf("%llu %i %s", time, id + 1, str);
// 	pthread_mutex_unlock(&data->mut_print);
// }

int	print_mandatory_format(t_data *data, int id, int option)
{
	static char	*lookup[6] = {
		"%lld %d is eating\n",
		"%lld %d is sleeping\n",
		"%lld %d is thinking\n",
		"%lld %d has taken their left fork\n",
		"%lld %d has taken their right fork\n",
		"%lld %d died\n"};
	long long	time;
	long long	ph_start_time;

	ph_start_time = ft_get_start_time(data);
	time = ft_get_time() - ph_start_time; // someone suggested to add /1000. Print the values later to find out
	pthread_mutex_lock(&data->mut_print);
	if (option != 5 && are_we_done(data) == 1)// if we're done but option other than 5 : do not print in case of impending doom
		return (pthread_mutex_unlock(&data->mut_print), 1);
	printf(lookup[option], time, id + 1);
	pthread_mutex_unlock(&data->mut_print);
	return (0);
}


/*  Print mandatory format :

Envoyer le status et faire un test de vie ou de mort, ou de are they full ?
It's currently being written in all_we_done (in die.c)*/

