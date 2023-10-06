/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:21:03 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/06 10:39:10 by letnitan         ###   ########.fr       */
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

//prints error and frees data
void	ft_error(t_data	*data)
{
	printf("ERROR");
	ft_free_data(data);
}

void	print_with_mutex(char *str, t_data *data)
{
	pthread_mutex_lock(&data->mut_print);
	printf("\n%s\n", str);
	pthread_mutex_unlock(&data->mut_print);
}

void	print_mandatory_format(t_data *data, int id, char *str)
{
	long long	time;
	long long	ph_start_t;

	ph_start_t = data->start_time;
	time = ft_get_time() - ph_start_t;
	pthread_mutex_lock(&data->mut_print);
	printf("%llu %i %s\n", time, id, str);
	pthread_mutex_unlock(&data->mut_print);
}
