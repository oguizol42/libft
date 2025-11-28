/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:13:43 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/27 22:31:29 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	pos;

	dstlen = 0;
	srclen = 0;
	pos = 0;
	while ((dstlen < size) && (dst[dstlen] != '\0'))
		++dstlen;
	while (src[srclen] != '\0')
		++srclen;
	if ((dstlen >= size) || size == 0)
		return (size + srclen);
	while (((dstlen + pos) < (size - 1)) && (src[pos] != '\0'))
	{
		dst[dstlen + pos] = src[pos];
		++pos;
	}
	dst[dstlen + pos] = '\0';
	return (dstlen + srclen);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while ((src[i] != '\0') && (i < (size - 1)))
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		++i;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		++s;
		++count;
	}
	return (count);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptrjoin;
	char	*tofree;
	char	empty[1];
	size_t	lens1;
	size_t	lens2;

	ptrjoin = NULL;
	empty[0] = '\0';
	if (!s1)
		s1 = empty;
	if (!s2)
		s2 = empty;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptrjoin = (char *)malloc(lens1 + lens2 + 1);
	if (ptrjoin)
	{
		ft_strlcpy(ptrjoin, s1, lens1 + 1);
		ft_strlcat(ptrjoin, s2, lens1 + lens2 + 1);
	}
	tofree = (char *)s2;
	free (tofree);
	tofree = NULL;
	return (ptrjoin);
}

int	strcut(t_lststash *node, char **strj)
{
	int		i;

	i = 0;
	free (node->stash);
	node->stash = NULL;
	while (((*strj)[i] != '\0') && ((*strj)[i] != '\n'))
		++i;
	if (((*strj)[i] == '\0') && (node->endofi == 1))
		return (0);
	if ((*strj)[i] == '\0')
	{
		node->stash = *strj;
		return (1);
	}
	node->stash = ft_strjoin("", (&((*strj)[i + 1])));
	(*strj)[i + 1] = '\0';
	(*strj) = ft_strjoin("", (*strj));
	return (0);
}

//Fait un read du fichier
	//Associe les deux string
	//Si une fin de ligne detectee=> range le reste dans stash 
	//								 Si fin de ligne == fin de fichier: passe endofi a 1
	//								 renvoie la str
	//Repart au read du fichier.

/*
int	strcut(t_lststash *node, char **strj)
{
	char	*str;
	size_t	i;

	i = 0;
	while ((strj && *strj) && ((*strj)[i] != '\0') && ((*strj)[i] != '\n'))
		++i;
	if (((*strj)[i] == '\0') && (node->endofi == 0))
		return (0);
	free (node->stash);
	node->stash = NULL;
	if (i == ft_strlen(*strj))// || ((i + 1) == ft_strlen(*strj)))
		return (1);
	node->stash = ft_strjoin("", &((*strj)[i + 1]));
	(*strj)[i + 1] = '\0';
	str = ft_strjoin("", (*strj));
	free (*strj);
	*strj = str;
	return (1);
}
*/