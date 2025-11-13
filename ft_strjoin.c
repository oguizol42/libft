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

/*
int	main(int argc, char **argv)
{
	char	*sconc;

	sconc = NULL;
	if (argc > 1)
	{
		printf("Chaine1: %s\n", argv[1]);
		printf("Chaine2: %s\n", argv[2]);
		sconc = ft_strjoin(argv[1], argv[2]);
		if (sconc)
			printf("\nChaine retour: %s\n", sconc);
		else
			printf("\nProbleme d'allocation\n");


	}
	return (0);
}
		
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	return (sconc)
*/
