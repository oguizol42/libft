/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:57:10 by oguizol           #+#    #+#             */
/*   Updated: 2025/12/02 19:49:45 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	cutline(t_line *line, char *readfd, int len)
{
	char	*str;
	char	*strfree;
	int		i;

	i = 0;
	str = NULL;
	str = ft_strjoin(readfd, NULL);
	strfree = line->line;
	line->line = ft_strjoin(line->line, str);
	free (strfree);
	while (((line->line)[i] != '\0') && ((line->line)[i] != '\n'))
		++i;
	if (((line->line)[i] == '\0') && (len < BUFFER_SIZE))
		return (0);
	if ((line->line)[i] == '\0')
		return (1);
	str = ft_strjoin(&((line->line)[i + 1]), NULL);
	if (str)
		line->stash = ft_strjoin (NULL, str);
	(line->line)[i + 1] = '\0';
	line->line = ft_strjoin (NULL, line->line);
	return (0);
}

void	deltline(t_line **lst, t_line *tofree)
{
	t_line	*temp;

	if (!(*lst) || !tofree)
		return ;
	tmp = *lst;
	while ((tmp != tofree) && (tmp->next != tofree))
		tmp = tmp->next;
	free (tofree->stash);
	free (tofree->line);
	tofree->stash = NULL;
	tofree->line = NULL;
	if (tmp == *lst)
		*lst = (*lst)->next;
	else
		tmp->next = tofree->next;
	free (tofree);
}

void	get_line_fd(t_line *line)
{
	char	*readfd;
	int		endofi;
	int		len;

	endofi = 1;
	len = 0;
	readfd = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!readfd)
	{
		endofi = cutline(line, readfd, len);
		return ;
	}
	while (endofi)
	{
		len = read(line->fd, readfd, BUFFER_SIZE);
		if ((len < 0) || ((len == 0) && ((line->line == NULL)
					|| (*(line->line) == '\0'))))
			endofi = deltline(line);
		else
		{
			readfd[len] = '\0';
			endofi = cutline(line, readfd, len);
		}
	}
	free (readfd);
}

t_line	*get_node(t_line **lst, int fd)
{
	t_line	*node;
	t_line	*poslst;

	node = *lst;
	while (node && (node->fd != fd))
		node = node->next;
	if (!node)
	{
		node = init_node(fd);
		if (!(*lst))
			*lst = node;
		else
		{
			poslst = *lst;
			while (poslst->next != NULL)
				poslst = poslst->next;
			poslst->next = node;
		}
	}
	return (node);
}

char	*get_next_line(int fd)
{
	static t_line	*lst;
	t_line			*line;

	if ((fd < 0) || (fd == 1) || (fd == 2) || (BUFFER_SIZE <= 0))
		return (NULL);
	line = get_node(&lst, fd);
	if (!line)
		return (NULL);
	line->line = NULL;
	line->line = ft_strjoin(NULL, line->stash);
	line->stash = NULL;
	get_line_fd(line);
	return (line->line);
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

	fd = open("TEXT3", O_RDONLY);

	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);

	close(fd);

	printf("Avec fd -1: %s\n", get_next_line(-1));
	printf("Avec fd 0: %s\n", get_next_line(0));
	printf("Avec fd 1: %s\n", get_next_line(1));
	printf("Avec fd 2: %s\n", get_next_line(2));
	printf("Avec fd 3: %s\n", get_next_line(3));
	return (0);
}*/
