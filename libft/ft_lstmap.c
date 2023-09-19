/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letnitan <letnitan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:00:24 by letnitan          #+#    #+#             */
/*   Updated: 2022/11/28 17:31:47 by letnitan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*liste_temp;
	t_list	*nouvelle_liste;
	void	*content;

	nouvelle_liste = NULL;
	if (f == NULL)
		return (NULL);
	while (lst)
	{
		content = (f)(lst->content);
		liste_temp = ft_lstnew(content);
		if (liste_temp == NULL)
		{
			if (del)
			{
				(*del)(content);
				ft_lstclear(&liste_temp, del);
				ft_lstclear(&nouvelle_liste, del);
				return (NULL);
			}
		}
		ft_lstadd_back(&nouvelle_liste, liste_temp);
		lst = lst->next;
	}
	return (nouvelle_liste);
}
