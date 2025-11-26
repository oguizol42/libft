/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:13:02 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/26 11:57:35 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*doread(int fd, t_lststash *node)
{
	char	*str;
	char	*strj;
	ssize_t	len;

	str = NULL;
	strj = NULL;
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	if (node->endofi == 0)
		len = read(fd, str, BUFFER_SIZE);
	if (len == -1)
		return (NULL);
	str[len] = '\0';
	if (len < BUFFER_SIZE)
		node->endofi = 1;
	strj = ft_strjoin(node->stash, str);
	free (str);
	str = NULL;
	if (!strj)
		return (NULL);
	str = strcut(node, strj);
	return (str);
}

void	addnode(t_lststash *list, t_lststash *node)
{
	while (list && (list->next != NULL))
		list = list->next;
	if (list && node)
		list->next = node;
}

void	delnode(t_lststash **list, t_lststash *node)
{
	t_lststash	*listpos;

	listpos = *list;
	while ((listpos != node) && (listpos->next != node))
		listpos = listpos->next;
	if (listpos == node)
		*list = (*list)->next;
	else
		listpos->next = node->next;
	free (node);
	node = NULL;
}

void	initnode(int fd, t_lststash **node)
{
	*node = NULL;
	*node = (t_lststash *)malloc(sizeof(t_lststash));
	if (*node)
	{
		(*node)->fd = fd;
		(*node)->stash = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		(*node)->endofi = 0;
		(*node)->next = NULL;
		if (!((*node)->stash))
		{
			free(*node);
			(*node) = NULL;
		}
		else
			(*(*node)->stash) = '\0';
	}
}

char	*get_next_line(int fd)
{
	static t_lststash	*list;
	t_lststash			*node;
	char				*str;

	str = NULL;
	if (!list)
	{
		initnode(fd, &list);
		node = list;
	}
	else
	{
		node = list;
		while (node && (node->fd != fd))
			node = node->next;
		if (!node)
		{
			initnode(fd, &node);
			addnode(list, node);
		}
	}
	str = doread(fd, node);
	if (node && !(node->stash) && (node->endofi == 1))
		delnode(&list, node);
	return (str);
}
