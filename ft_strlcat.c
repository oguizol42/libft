/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:56:52 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/06 15:57:58 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length;

	length = 0;
	while (*dst != '\0')
	{
		++dst;
		++length;
		--size;
	}
	while ((size > 1) && (*src != '\0'))
	{
		*dst = *src;
		++dst;
		++src;
		++length;
		--size;
	}
	*dst = '\0';
	while (*src != '\0')
	{
		++src;
		++length;
	}
	return (length);
}

/*
int	main (void)
{
	char	src[] = "Au revoir";
	char	dest1[25] = "Bonjour, ";
	char	*dest2;
	size_t	length;

	length = 0;
	dest2 = (char *) malloc (sizeof(char) * 15);
	printf("ESSAI1: src: %s, dest: %s", src, dest1);
	length = ft_strlcat(dest1, src, 25);
	printf("\nApres strlcat:\nsrc: %s, dest: %s", src, dest1);
	printf("\nLongueur: %zu\n", length);

	ft_strlcpy(dest2, "Bonjour, ", 15);
	length = 0;
	printf("ESSAI2: src: %s, dest: %s", src, dest2);
	length = ft_strlcat(dest2, src, 15);
	printf("\nApres strlcat:\nsrc: %s, dest: %s", src, dest2);
	printf("\nLongueur: %zu\n", length);
	free (dest2);
	return (0);
}
*/