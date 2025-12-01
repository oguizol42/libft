/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:57:10 by oguizol           #+#    #+#             */
/*   Updated: 2025/12/01 17:26:08 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	cutline(t_line *line, char *readfd, size_t	len)
{
	char	*tmp;
	int		i;

	i = 0;
	if ((len == 0) && (*(line->line) == '\0'))
	{
		delline(line, readfd);
		return (1);
	}
	readfd[len] = '\0';
	tmp = line->line;
	line->line = ft_strjoin((line->line), readfd);
	free(tmp);
	while (((line->line)[i] != '\0') && ((line->line)[i] != '\n'))
		++i;
	if (((line->line)[i] == '\0') && (len < BUFFER_SIZE))
		return (1);
	if ((line->line)[i] == '\0')
		return (0);
	ft_strlcat((line->stash), &((line->line)[i + 1]), (BUFFER_SIZE + 1));
	(line->line)[i + 1] = '\0';
	tmp = line->line;
	line->line = ft_strjoin("", tmp);
	return (1);
}

int	delline(t_line *line, char *str)
{
	free (str);
	str = line->line;
	free (str);
	line->line = NULL;
	*(line->stash) = '\0';
	
	return (1);
}

void	get_line_fd(t_line *line)
{
	char	*readfd;
	int		endli;
	int		len;

	len = 0;
	endli = 0;
	line->line = ft_strjoin((line->stash), (line->line));
	*(line->stash) = '\0';
	while (!endli)
	{
		readfd = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (readfd)
		{
			len = read(line->fd, readfd, BUFFER_SIZE);
			if (len < 0)
				endli = delline(line, readfd);
			else
				endli = cutline(line, readfd, len);
		}
		else
			delline(line, NULL);
	}
}

char	*get_next_line(int fd)
{
	static t_line	line;

	line.line = NULL;
	if ((fd < 0) || (fd == 1) || (fd == 2) || (BUFFER_SIZE == 0))
		return (NULL);
	line.fd = fd;
	get_line_fd(&line);
	return (line.line);
}


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
/*
	printf("Avec fd -1: %s\n", get_next_line(-1));
	printf("Avec fd 0: %s\n", get_next_line(0));
	printf("Avec fd 1: %s\n", get_next_line(1));
	printf("Avec fd 2: %s\n", get_next_line(2));
	printf("Avec fd 3: %s\n", get_next_line(3));*/
	return (0);
}
