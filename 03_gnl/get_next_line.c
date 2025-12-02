/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:57:10 by oguizol           #+#    #+#             */
/*   Updated: 2025/12/02 18:39:56 by oguizol          ###   ########.fr       */
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

int	deltline(t_line *tofree)
{
	free (tofree->stash);
	free (tofree->line);
	tofree->stash = NULL;
	tofree->line = NULL;
	return (0);
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

char	*get_next_line(int fd)
{
	static t_line	line;

	line.line = NULL;
	if ((fd < 0) || (fd == 1) || (fd == 2) || (BUFFER_SIZE <= 0))
	{
		free(line.stash);
		line.stash = NULL;
		return (NULL);
	}
	line.fd = fd;
	line.line = ft_strjoin(NULL, line.stash);
	line.stash = NULL;
	get_line_fd(&line);
	return (line.line);
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
