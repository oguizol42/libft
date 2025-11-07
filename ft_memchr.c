/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:49:21 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/07 12:30:59 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scr;
	unsigned char	ch;
	void			*scrv;
	size_t			i;

	scr = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (scr[i] == ch)
		{
			scrv = &scr[i];
			return (scrv);
		}
		++i;
	}
	return (NULL);
}

/*
int	main(int argc, char **argv)
{
	char	*result;
	int		c;
	int		size;

	result = NULL;
	size = 0;
	c = 0;
	if (argc > 2)
	{
		c = *argv[2];
		printf("\nChaine: %s\nOccurence: %c\n", argv[1], c);
		printf("Nombre d'octets de recherche: ");
		scanf("%d", &size);
		result = ft_memchr(argv[1], c, size);
		if (result != NULL)
			printf("Retour chaine occurence: %s\n", result);
		else
			printf("Occurence non trouvee\n");
	}
	return (0);
}
*/