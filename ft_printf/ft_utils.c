/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:55:34 by letnitan          #+#    #+#             */
/*   Updated: 2022/12/30 12:09:07 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_nbrcounter(long long nb, int base_len)
{
	int	counter;

	counter = 0;
	if (nb == 0)
		return (1);
	else if (nb < 0)
	{
		nb *= -1;
		counter++;
	}
	while (nb > 0)
	{
		nb = nb / base_len;
		counter++;
	}
	return (counter);
}

int	ft_putnbr(long long n, char *base, int trigger)
{
	unsigned long long	nbr;
	size_t				base_len;

	base_len = ft_strlen(base);
	nbr = n;
	if (n < 0 && trigger == 1)
	{
		nbr = n * -1;
		ft_putchar('-');
	}
	if (nbr > base_len - 1)
		ft_putnbr(nbr / base_len, base, 0);
	ft_putchar(base[nbr % base_len]);
	return (ft_nbrcounter(n, base_len));
}

int	ft_ptrlen(unsigned long long n, int base_len)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / base_len;
		nbr_len++;
	}
	return (nbr_len);
}

int	ft_pointer(unsigned long long ptr, char *base, int trigger)
{
	unsigned long long	nbr;

	nbr = ptr;
	if (nbr == 0)
		return (write(1, "(nil)", 5));
	if (trigger == 0)
		write(1, "0x", 2);
	if (nbr > 15)
		ft_pointer(nbr / 16, base, 1);
	ft_putchar(base[nbr % 16]);
	return (ft_ptrlen(nbr, ft_strlen(base)) + 2);
}
