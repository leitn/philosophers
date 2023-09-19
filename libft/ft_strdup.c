/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:41:15 by letnitan          #+#    #+#             */
/*   Updated: 2022/11/22 12:44:14 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*strduplicate;

	len = ft_strlen((char *)s);
	strduplicate = ft_calloc(len + 1, sizeof(char));
	if (!(strduplicate))
		return (NULL);
	ft_memcpy(strduplicate, s, len);
	return (strduplicate);
}
