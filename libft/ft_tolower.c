/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:40:57 by letnitan          #+#    #+#             */
/*   Updated: 2022/11/10 18:41:01 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_uppercase(char c)
{
	if ((c >= 'A' && c <= 'Z'))
		return (0);
	else
		return (1);
}

int	ft_tolower(int c)
{
	if (ft_uppercase(c) == 0)
		return (c + 32);
	else
		return (c);
}
