/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:21:03 by letnitan          #+#    #+#             */
/*   Updated: 2023/10/08 20:12:07 by letnitan         ###   ########.fr       */
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
