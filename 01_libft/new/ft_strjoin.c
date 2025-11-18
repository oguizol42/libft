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
	char	empty[1];
	size_t	lens1;
	size_t	lens2;

	ptrjoin = NULL;
	empty[0] = '\0';
	if (!s1)
		s1 = empty;
	if (!s2)
		s2 = empty;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptrjoin = (char *)malloc(lens1 + lens2 + 1);
	if (ptrjoin)
	{
		ft_strlcpy(ptrjoin, s1, lens1 + 1);
		ft_strlcat(ptrjoin, s2, lens1 + lens2 + 1);
	}
	return (ptrjoin);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*ptrjoin;

	ptrjoin = NULL;
	if (argc > 2)
	{
		printf("Chaine1: %s\n", argv[1]);
		printf("Chaine2: %s\n", argv[2]);
		ptrjoin = ft_strjoin(argv[1], argv[2]);
	}
	printf ("\nApres strjoin: %s", ptrjoin);
	
	printf("\n\n\nAvec ft_strjoin(NULL, NULL)");
	ptrjoin = ft_strjoin(NULL, NULL);
	printf ("\nApres strjoin: %s", ptrjoin);

	printf("\n\n\nAvec ft_strjoin(NULL, \"\")");
        ptrjoin = ft_strjoin(NULL, "");
        printf ("\nApres strjoin: %s", ptrjoin);

	printf("\n\n\nAvec ft_strjoin(\"\", NULL)");
        ptrjoin = ft_strjoin("", NULL);
        printf ("\nApres strjoin: %s", ptrjoin);

	printf("\n\n\nAvec ft_strjoin(NULL, \"bonjour\")");
        ptrjoin = ft_strjoin(NULL, "bonjour");
        printf ("\nApres strjoin: %s", ptrjoin);

        printf("\n\n\nAvec ft_strjoin(\"bonjour\", NULL)");
        ptrjoin = ft_strjoin("bonjour", NULL);
        printf ("\nApres strjoin: %s\n\n", ptrjoin);

	return (0);
}
*/
