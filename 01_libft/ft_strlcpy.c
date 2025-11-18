/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:04:20 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/09 12:54:48 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*
int	main(int argc, char **argv)
{
	size_t	size;
	size_t	result;
	size_t	result2;
	char	dst[1000];
	//char	dst2[1000];
	
	size = 0;
	result = 0;
	result2 = 0;
	if (argc > 1)
	{
		printf("Chaine envoyee: %s\n", argv[1]);
		printf("Taille du tampon: ");
		scanf("%zu", &size);
		result = ft_strlcpy(dst, argv[1], size);
		//result2 = strlcpy(dst2, argv[1], size);
		printf("\nTaille de la chaine avec ft_strlcpy: %zu\n", result);
		printf("Chaine dest avec ft_strlcpy: %s\n", dst);
	}
	return (0);
}
*/
