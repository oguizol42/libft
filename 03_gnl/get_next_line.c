/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:03:20 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/28 16:52:48 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lstfd	*addnode(t_lstfd *list, int fd)
{
	list = (t_lstfd *)malloc(sizeof(t_lstfd));
	if (!list)
		return (NULL);
	list->stash = (char *)malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!(list->stash))
	{
		free (list);
		return (NULL);
	}
	list->fd = fd;
	list->endofi = 0;
	list->next = NULL;
	return (list);
}

char	*get_next_line(int fd)
{
	static t_lstfd	*list;
	char			*str;

	str = NULL;
	if ((fd < 0) || (BUFFER_SIZE < 1))
		return (NULL);
	if (!(list))
		addnode(list, fd);
	if (!list)
		return (NULL);
	return (str);
}

/*
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{
	char	*str;
	int		fd;

	str = NULL;
	fd = open("TEXT1", O_RDONLY);
	str = get_next_line(fd);
	printf("\nTexte recupere:\n%s\n", str);
	free (str);
	close (fd);
	return (0);
}
*/