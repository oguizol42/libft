/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:47:04 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/13 20:53:00 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptrjoin;
	size_t	lens1;
	size_t	lens2;

	ptrjoin = NULL;
	if (s1)
		lens1 = ft_strlen(s1);
	else
		lens1 = 0;
	if (s2)
		lens2 = ft_strlen(s2);
	else
		lens2 = 0;
	ptrjoin = (char *)malloc(lens1 + lens2 + 1);
	if (ptrjoin)
	{
		ft_strlcpy(ptrjoin, s1, lens1 + 1);
		ft_strlcat(ptrjoin, s2, lens1 + lens2 + 1);
	}
	return (ptrjoin);
}

/*

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptrjoin;

	ptrjoin = NULL;
	if (s1 && s2)
	{
		ptrjoin = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (ptrjoin)
		{
			ft_strlcpy(ptrjoin, s1, (ft_strlen(s1) + 1));
			ft_strlcat(ptrjoin, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
		}
	}
	return (ptrjoin);
}

int	main(int argc, char **argv)
{
	char	*ptrjoin;

	ptrjoin = NULL;
	if (argc == 3)
	{
		printf("Chaine1: %s\n", argv[1]);
		printf("Chaine2: %s\n", argv[2]);
		ptrjoin = ft_strjoin(argv[1], argv[2]);
	}
	if (argc == 4)
	{
		printf("\nNULL en dest\n");
		ptrjoin = ft_strjoin(NULL, argv[2]);
	}
	if (argc == 5)
	{
		printf("\nNULL en source\n");
		ptrjoin = ft_strjoin(argv[2], NULL);
	}
	if (argc == 6)
	{
		printf("\nNULL sur les deux\n");
		ptrjoin = ft_strjoin(NULL, NULL);
	}
	if (ptrjoin)
	{
		printf("\nChaine retour: %s\n", ptrjoin);
		printf("Longueur: %zu\n", ft_strlen(ptrjoin));
	}
	else
		printf("\nRetour NULL\n");
	return (0);
}
*/
