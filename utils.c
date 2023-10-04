/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:21:03 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/04 15:50:20 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int		count;
	long	result;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while (str[count] == '\r' || str[count] == '\t' || str[count] == ' '
		|| str[count] == '\f' || str[count] == '\v' || str[count] == '\n')
		count++;
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	if (!(str[count] >= '0' && str[count] <= '9'))
		return (0);
	while (str[count] >= '0' && str[count] <= '9')
		result = result * 10 + (str[count++] - '0');
	return (result * sign);
}

void	ft_error(t_data	*data)
{
	printf("ERROR");
	free(data);
}
