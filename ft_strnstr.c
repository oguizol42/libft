/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:38:02 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/07 16:51:12 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while ((i < len) && (big[i] != '\0'))
	{
		j = 0;
		if (big[i] == little[j])
		{
			while ((big[i + j] != '\0') && (i + j < len)
				&& (big[i + j] == little[j]))
			{
				++j;
				if (little[j] == '\0')
					return ((char *)(&big[i]));
			}
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

	result = NULL;
	c = 0;
	if (argc > 2)
	{
		printf("\nPremiere chaine big   : %s", argv[1]);
		printf("\nDeuxieme chaine little: %s", argv[2]);
		printf("\nChoisissez le nombre de caracteres testes: ");
		scanf("%d", &c);
		result = ft_strnstr(argv[1], argv[2], c);
		if (result)
			printf("\nOccurence trouvee: %s\n", result);
		else
			printf("\nOccurence non trouvee\n");
	}
	return (0);
}
*/