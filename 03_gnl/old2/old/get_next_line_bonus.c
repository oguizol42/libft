/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:29:35 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/27 16:56:31 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*doread(t_lststash *node)
{
	char	*str;
	char	*strj;
	ssize_t	len;

	strj = ft_strjoin("", node->stash);
	while (!(strcut(node, &strj)))
	{
		str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return (NULL);
		len = read(node->fd, str, BUFFER_SIZE);
		if (len < 0)
		{
			free (str);
			return (NULL);
		}
		str[len] = '\0';
		strj = ft_strjoin(strj, str);
		free(str);
		if (!strj)
			return (NULL);
		if (len < BUFFER_SIZE)
			node->endofi = 1;
	}
	return (strj);
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

t_lststash	*initnode(int fd, t_lststash **node)
{
	*node = NULL;
	*node = (t_lststash *)malloc(sizeof(t_lststash));
	if (*node)
	{
		(*node)->fd = fd;
		(*node)->stash = NULL;
		(*node)->endofi = 0;
		(*node)->next = NULL;
	}
	return (*node);
}

char	*get_next_line(int fd)
{
	static t_lststash	*list;
	t_lststash			*node;
	char				*str;

	str = NULL;
	if ((fd < 0) || (BUFFER_SIZE < 0))
		return (NULL);
	if (!list)
		node = initnode(fd, &list);
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
	str = doread(node);
	if (!str || (node && (*(node->stash) == '\0') && (node->endofi == 1)))
		delnode(&list, node);
	return (str);
}

/*
# include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*str;
	
	fd = open("TEXT1", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	close (fd);
	return (0);
}

# include <stdio.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		fd2;
	char	*str;
	
	fd = open("TEXT1", O_RDONLY);
	fd2 = open("TEXT2", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd2);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd2);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd2);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd2);
	printf("%s", str);
	free (str);
	str = get_next_line(fd);
	printf("%s", str);
	free (str);
	str = get_next_line(fd2);
	printf("%s", str);
	free (str);
	return (0);
}
*/