/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:11:38 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/06 12:02:52 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*news;
	unsigned char		*newd;

	newd = dest;
	news = src;
	if (src >= dest)
	{
		while (n > 0)
		{
			*newd = *news;
			++newd;
			++news;
			--n;
		}
	}
	else
	{
		while (n > 0)
		{
			newd[n - 1] = news[n - 1];
			--n;
		}
	}
	return (dest);
}

/*
int	main(void)
{
	unsigned char	aff[] = "Salut, ca va ?";
	unsigned char	aff0[] = "Salut, ca va ?";
	unsigned char	aff1[] = "Salut, ca va ?";
	unsigned char	*aff2;

	printf("\n\nESSAI 1, copie 4 premiers caracteres, ");
	printf("destination et source identique:\n");
	aff2 = NULL;
	printf ("Avant src: %s", aff);
	aff2 = ft_memmove(aff, aff, 4);
	printf ("\nApres src: %s", aff);
	printf ("\nApres dest: %s", aff2);

	printf("\n\nESSAI 1, copie 4 premiers caracteres, ");
	printf("destination = source +2:\n");
	aff2 = NULL;
	printf ("Avant src: %s", aff0);
	aff2 = ft_memmove(&aff0[2], aff0, 4);
	printf ("\nApres src: %s", aff0);
	printf ("\nApres dest: %s", aff2);

	printf("\n\nESSAI 1, copie 4 premiers caracteres, ");
	printf("source = destination +2:\n");
	aff2 = NULL;
	printf ("Avant src: %s", &aff1[2]);
	printf ("\nAvant dest: %s", aff1);
	aff2 = ft_memmove(aff1, &aff1[2], 4);
	printf ("\nApres src: %s", &aff1[2]);
	printf ("\nApres dest: %s", aff2);
	return (0);
}
*/