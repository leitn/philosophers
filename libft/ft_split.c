/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:37:24 by letnitan          #+#    #+#             */
/*   Updated: 2022/11/22 20:38:52 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*word_put(const char *s, char c)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	return (str);
}

static size_t	str_count(char const *s, char c)
{
	size_t	i;
	size_t	str_count;

	i = 0;
	str_count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i + 1] != '\0')
			i++;
		if (s[i] != c)
			str_count++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (str_count);
}

int	fill_tab(char **tab_proxy, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] && str_count(s, c) != 0)
	{
		while (s[i] == c && s[i + 1] != '\0')
			i++;
		if (s[i] != c)
			tab_proxy[j++] = word_put(&s[i], c);
		if (!tab_proxy[j - 1])
			return (1);
		while (s[i] != c && s[i + 1] != '\0')
			i++;
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**str_tab;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = str_count(s, c);
	str_tab = malloc(sizeof(char *) * (i + 1));
	if (str_tab == NULL)
		return (NULL);
	str_tab[i] = NULL;
	if (fill_tab(str_tab, s, c) == 1)
	{
		while (i > 0)
			free(str_tab[--i]);
		free(str_tab);
		str_tab = NULL;
	}
	return (str_tab);
}
