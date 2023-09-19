/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:20:10 by letnitan          #+#    #+#             */
/*   Updated: 2022/11/22 16:07:44 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	i;

	i = 0;
	if (dst == NULL)
		dstlen = 0;
	else
		dstlen = ft_strlen(dst);
	if (size < dstlen + 1)
		return (size + ft_strlen(src));
	if (size > dstlen + 1)
	{
		while (src[i] && (dstlen + i < size - 1))
		{
			dst[dstlen + i] = src[i];
			i++;
		}
	}
	dst[dstlen + i] = '\0';
	return (ft_strlen(src) + dstlen);
}
