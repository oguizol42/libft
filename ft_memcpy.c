/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:48:40 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/06 11:48:22 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*news;
	unsigned char		*newd;

	newd = dest;
	news = src;
	while (n > 0)
	{
		*newd = *news;
		++newd;
		++news;
		--n;
	}
	return (dest);
}

/*
int	main(void)
{
	unsigned char	aff[] = "ABCDEF";
	unsigned char	*aff2;

	aff2 = NULL;
	printf ("Avant: %s", aff);
	aff2 = ft_memcpy(aff, "EFGHIJ", 3);
	printf ("\nApres: %s", aff);
	printf ("\nApres2: %s", aff2);
	return (0);
}
*/