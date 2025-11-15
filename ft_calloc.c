/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:46:07 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/10 11:16:04 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memalloc;
	size_t	i;

	i = 0;
	if ((nmemb == 0) || (size == 0))
		return (malloc (0));
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	memalloc = malloc (nmemb * size);
	if (memalloc)
	{
		while (i < (nmemb * size))
		{
			((char *)memalloc)[i] = 0;
			++i;
		}
		return (memalloc);
	}
	return (0);
}

/*
int	main(void)
{
	char	*test;
	size_t	size;
	size_t	nmemb;
	size_t	i;

	test = NULL;
	size = 0;
	nmemb = 0;
	i = 0;
	printf ("Taille max d'une case memoire max: %zu: ", SIZE_MAX);
	scanf ("%zu", &size);
	printf ("\nChoisissez le nombre de cases memoire: ");
	scanf ("%zu", &nmemb);
	test = ft_calloc(nmemb, size);
	if (errno == ENOMEM)
		printf ("\nTaille d'allocation memoire demandee trop grande\n");
	else
	{
		printf ("\nContenue de la memoire allouee:\n");
		while (i < (size * nmemb))
		{
			printf ("%d ", test[i]);
			++i;
		}
		printf ("\n");
	}
	return (0);
}
*/
