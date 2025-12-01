/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:03:20 by oguizol           #+#    #+#             */
/*   Updated: 2025/12/01 14:44:37 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	cutline(t_lstfd *node, char **line)
{
	int	i;

	i = 0;
	*(node->stash) = '\0';
	while (((*line)[i] != '\0') && ((*line)[i] != '\n'))
		++i;
	if (((*line)[i] == '\0') && (node->endofi != 1))
		return (1);
	if (((*line)[i] == '\0') && (node->endofi == 1))
	{	
		node->endofi = 0;
		return (0);
	}
	ft_strlcpy(node->stash, &((*line)[i + 1]), (BUFFER_SIZE + 1));
	(*line)[i + 1] = '\0';
	(*line) = ft_strjoin(NULL, (*line));
	return (0);
}

char	*get_line(t_lstfd *node)
{
	char	*strj;
	char	*str;
	char	*tmp;
	int		endg;
	int		len;

	endg = 1;
	len = 0;
	//Recuperation stash
	strj = ft_strjoin(node->stash, NULL);
	//Recuperation nouvelle ligne tant que aucune fin de ligne ou de fichier atteinte
	while (endg)
	{
		str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
		{
			free(strj);
			return (NULL);
		}
		len = read(node->fd, str, BUFFER_SIZE);
		if ((len < 0) || ((len == 0) && (*strj == '\0')))
		{
			free(strj);
			free(str);
			*(node->stash) = '\0';
			return (NULL);
		}
		str[len] = '\0';
		if (len < BUFFER_SIZE)
			node->endofi = 1;
		tmp = strj;
		strj = ft_strjoin(strj, str);
		free(tmp);
		endg = cutline(node, &strj);
	}
	//mettre dans le stash ce qu'il reste
	//Retourner chaine a envoyer
	return (strj);
}

char	*get_next_line(int fd)
{
	static t_lstfd	nodefd;
	char			*str;

	str = NULL;
	if ((fd < 0) || (fd == 1) || (fd == 2) || (BUFFER_SIZE < 1))
		return (NULL);
	nodefd.fd = fd;
	str = get_line(&nodefd);
	return (str);
}

/*
int	main(void)
{
	char	*str;
	int		fd1;
	int		fd2;

	str = NULL;
	fd1 = open("TEXT1", O_RDONLY);
	fd2 = open("TEXT2", O_RDONLY);
	str = get_next_line(fd1);
	printf("\nTexte recupere:\n%s\n", str);
	free (str);
	str = get_next_line(fd1);
	printf("\nTexte recupere:\n%s\n", str);
	free (str);
	str = get_next_line(fd1);
	printf("\nTexte recupere:\n%s\n", str);
	free (str);
	str = get_next_line(fd1);
	printf("\nTexte recupere:\n%s\n", str);
	free (str);

	str = get_next_line(fd2);
	printf("\nTexte recupere:\n%s\n", str);
	free (str);
	str = get_next_line(fd1);
	printf("\nTexte recupere:\n%s\n", str);
	free (str);
	str = get_next_line(fd2);
	printf("\nTexte recupere:\n%s\n", str);
	free (str);
	str = get_next_line(fd1);
	printf("\nTexte recupere:\n%s\n", str);
	free (str);
	str = get_next_line(fd2);
	printf("\nTexte recupere:\n%s\n", str);
	free (str);
	close (fd1);
	close (fd2);
	return (0);
}
*/