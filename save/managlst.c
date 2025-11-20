/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:45:31 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/20 12:25:54 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_strlist	*init_node(char *content)
{
	t_strlist	*new;

	new = NULL;
	new = (t_strlist *)malloc(sizeof(t_strlist));
	if (new)
	{
		new->content = content;
		new->next = NULL;
	}
	return (new);
}

void	addnode(t_strlist **lst, char *str)
{
	t_strlist	*new;
	t_strlist	*poslst;

	if (lst && str)
	{
		new = init_node(str);
		if (!new)
			return ;
		if (!(*lst))
			*lst = new;
		else
		{
			poslst = *lst;
			while (poslst->next != NULL)
				poslst = poslst->next;
			poslst->next = new;
		}
	}
}

void	freelst(t_strlist **lst)
{
	t_strlist	*next;

	while (*lst)
	{
		next = (*lst)->next;
		free ((*lst)->content);
		free (*lst);
		*lst = next;
	}
}
