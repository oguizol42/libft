/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:04:20 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/06 12:50:11 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while ((src[i] != '\0') && (i < (size - 1)))
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		++i;
	return (i);
}

/*
int	main(void)
{
	char	dest1[4];
	char	dest2[20];
	size_t	size;

	size = ft_strlcpy(dest1, "bonjour", 4);
	printf("\n\nCopie du mot bonjour ");
	printf("dans une chaine de taille 4 octets: %s", dest1);
	printf("\nTaille de la chaine source: %zu", size);

	size = ft_strlcpy(dest2, "bonjour", 20);
	printf("\n\nCopie du mot bonjour ");
	printf("dans une chaine de taille 20 octets: %s", dest2);
	printf("\nTaille de la chaine source: %zu", size);
	return (0);
}
*/