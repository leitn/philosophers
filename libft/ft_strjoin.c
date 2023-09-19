/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:00:43 by letnitan          #+#    #+#             */
/*   Updated: 2022/11/22 16:51:08 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*str;
	size_t				lentotal;
	long unsigned int	i;
	long unsigned int	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lentotal = (ft_strlen(s1) + ft_strlen(s2));
	str = malloc(sizeof(char) * (lentotal + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && i <= ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] && j <= ft_strlen(s2))
		str[i++] = s2[j++];
	str[lentotal] = '\0';
	return (str);
}
