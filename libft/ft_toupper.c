/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:27:23 by letnitan          #+#    #+#             */
/*   Updated: 2022/11/10 18:27:27 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lowercase(char c)
{
	if ((c >= 'a' && c <= 'z'))
		return (0);
	else
		return (1);
}

int	ft_toupper(int c)
{
	if (ft_lowercase(c) == 0)
		return (c - 32);
	else
		return (c);
}
