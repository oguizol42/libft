/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:05:18 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/07 13:18:08 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sch1;
	unsigned char	*sch2;

	i = 0;
	sch1 = (unsigned char *)s1;
	sch2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((sch1[i] == sch2[i]) && (i < n))
		++i;
	if (i == n)
		--i;
	return (sch1[i] - sch2[i]);
}

/*
int	main(int argc, char **argv)
{
	int		c;

	c = 0;
	if (argc > 2)
	{
		printf("\nChoisissez le nombre de caracteres testes: ");
		scanf("%d", &c);
		printf("\nPremiere chaine: %s", argv[1]);
		printf("\nDeuxieme chaine: %s", argv[2]);
		printf("\nResultat: %d\n", ft_memcmp(argv[1], argv[2], c));
	}
	return (0);
}
*/