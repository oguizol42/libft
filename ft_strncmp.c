/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:11:08 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/07 11:45:39 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
		++i;
	if (i == n)
		--i;
	return (s1[i] - s2[i]);
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
		printf("\nResultat: %d\n", ft_strncmp(argv[1], argv[2], c));
	}
	return (0);
}
*/