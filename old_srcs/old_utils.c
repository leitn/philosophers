/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:21:03 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 16:22:54 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//TO REVISE ! Currently refuses all non numericals
int	ft_atoi(char *str)
{
	int		count;
	long	result;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while (str[count] != '\0')
	{
		while (str[count] == '\r' || str[count] == '\t' || str[count] == ' '
			|| str[count] == '\f' || str[count] == '\v' || str[count] == '\n')
			count++;
		if (str[count] == '-')
			return (-1);
		if (!(str[count] >= '0' && str[count] <= '9'))
			return (-1);
		while (str[count] >= '0' && str[count] <= '9')
			result = result * 10 + (str[count++] - '0');
	}
	return (result * sign);

}

//prints error and FREES data
void	ft_error(t_data	*data)
{
	print_with_mutex("ERROR", data);
	ft_free_data(data);
}

//MUTEX. Prints a str.
void	print_with_mutex(char *str, t_data *data)
{
	pthread_mutex_lock(&data->mut_print);
	printf("\n%s\n", str);
	pthread_mutex_unlock(&data->mut_print);
}

//MUTEX. Prints action monitoring message in "time id str" format.
void	print_mandatory_format(t_data *data, int id, char *str)
{
	long long	time;
	long long	ph_start_t;

	ph_start_t = data->start_time;
	time = ft_get_time() - ph_start_t;
	pthread_mutex_lock(&data->mut_print);
	printf("%llu %i %s", time, id + 1, str);
	pthread_mutex_unlock(&data->mut_print);
}
