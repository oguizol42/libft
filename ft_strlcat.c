/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:43:45 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/09 17:35:01 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	pos;

	dstlen = 0;
	srclen = 0;
	pos = 0;
	while (dst[dstlen] != '\0')
		++dstlen;
	while (src[srclen] != '\0')
		++srclen;
	if ((dstlen > size) || size == 0)
		return (size + srclen);
	while (((dstlen + pos) < (size - 1)) && (src[pos] != '\0'))
	{
		dst[dstlen + pos] = src[pos];
		++pos;
	}
	dst[dstlen + pos] = '\0';
	return (dstlen + srclen);
}
