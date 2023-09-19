/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:14:10 by letnitan          #+#    #+#             */
/*   Updated: 2022/11/22 17:05:45 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	size;

	size = 0;
	while (size < n)
	{
		if (*((char *)s + size) == (char )c)
			return ((void *)s + size);
		size++;
	}
	return (NULL);
}
