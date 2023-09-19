/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:53:31 by letnitan          #+#    #+#             */
/*   Updated: 2022/12/30 12:44:43 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	checkflag(va_list args, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_pointer(va_arg(args, unsigned long long), \
						"0123456789abcdef", 0));
	else if ((c == 'd') || (c == 'i'))
		return (ft_putnbr((long long)va_arg(args, int), "0123456789", 1));
	else if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), "0123456789", 0));
	else if (c == 'x')
		return (ft_putnbr(va_arg(args, unsigned int), "0123456789abcdef", 1));
	else if (c == 'X')
		return (ft_putnbr(va_arg(args, unsigned int), "0123456789ABCDEF", 1));
	else if (c == '%')
		return (ft_putchar('%'));
	else
	{
		ft_putchar('%');
		return (ft_putchar(c) + 1);
	}
	return (0);
}

int	ft_printf(const char *mandatory_argument, ...)
{
	va_list	args;
	int		counter;
	int		i;

	va_start(args, mandatory_argument);
	counter = 0;
	i = 0;
	while (mandatory_argument[i])
	{
		if (mandatory_argument[i] == '%' && mandatory_argument[i + 1] != '\0')
		{
			counter = counter + checkflag(args, mandatory_argument[i + 1]);
			i++;
		}
		else
		{
			if (mandatory_argument[i] == '%' && \
				mandatory_argument[i + 1] == '\0')
				break ;
			counter += ft_putchar(mandatory_argument[i]);
		}
		i++;
	}
	va_end(args);
	return (counter);
}
