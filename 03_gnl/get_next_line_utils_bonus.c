/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:13:43 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/25 20:54:36 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	return (ptrjoin);
}

char	*strcut(t_lststash *list, t_lststash *node, char *strj)
{
	char	*str;
	int		len;
	int		lenj;

	str = NULL;
	while (strj && (strj[len] != '\n') && (strj[len] != '\0'))
		++len;
	free(node->stash);
	node->stash = NULL;
	if (len == ft_strlen(strj))
		str = strj;
	else
	{
		str = (char *)malloc(sizeof(char) * (len + 2));
		if (str)
			ft_strlcpy(str, strj, (len + 2));
		lenj = ft_strlen(&(strj[len + 1]));
		node->stash = (char *)malloc(sizeof(char) * (lenj + 1));
		if (node->stash)
			ft_strlcpy(node->stash, (&(strj[len + 1])), (lenj + 1));
		free (strj);
	}
	return (str);
}
