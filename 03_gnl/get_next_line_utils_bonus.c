/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:58:10 by oguizol           #+#    #+#             */
/*   Updated: 2025/12/02 19:51:34 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptrjoin;
	char	*tmp;
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
	tmp = (char *)s2;
	if (s2 != empty)
		free (tmp);
	return (ptrjoin);
}

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

t_line	*init_node(int fd)
{
	t_line	*node;

	node = (t_line *)malloc(sizeof(t_line));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->stash = NULL;
	node->line = NULL;
	node->next = NULL;
	return (node);
}
