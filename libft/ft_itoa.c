/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:34:57 by letnitan          #+#    #+#             */
/*   Updated: 2022/11/21 15:35:00 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countchar(int n)
{
	size_t			i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	if (n < 0)
	{
		nb = n * (-1);
		i++;
	}
	else
		nb = n;
	while (nb != 0 || i == 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t			i;
	size_t			j;
	char			*str;
	long			nb;

	i = ft_countchar(n);
	nb = n;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	j = 0;
	if (n < 0)
	{
		str[j++] = '-';
		nb = nb * (-1);
	}
	str[i] = '\0';
	while (i > j)
	{
		str[--i] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
