/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:21:03 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/04 18:05:26 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//refuses all non numericals
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

//prints error and frees data
void	ft_error(t_data	*data)
{
	printf("ERROR");
	ft_free_data(data);
}
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
