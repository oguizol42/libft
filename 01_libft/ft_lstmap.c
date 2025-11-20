/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:46:12 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/17 11:53:17 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;

	newlst = NULL;
	while (lst)
	{
		newnode = ft_lstnew(lst->content);
		if (!newnode)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		newnode->content = f(newnode->content);
		if (!(newnode->content))
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		if (!newlst)
			newlst = newnode;
		else
			ft_lstadd_back(&newlst, newnode);
		lst = lst->next;
	}
	return (newlst);
}
