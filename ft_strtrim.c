/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:18:30 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/13 14:21:43 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*res;

	res = NULL;
	if (s1 && set)
	{
		start = 0;
		end = ft_strlen(s1) - 1;
		while (s1[start] != '\0' && ft_strchr(set, s1[start]))
			++start;
		while ((end >= 0) && (ft_strchr(set, s1[end])))
			--end;
		res = ft_substr(s1, start, (end - start + 1));
	}
	if (s1 && !(set))
		return (ft_strdup(s1));
	return (res);
}

/*
int	main(int argc, char **argv)
{
	char	*result;

	result = NULL;
	if (argc > 2)
	{
		result = ft_strtrim(argv[1], argv[2]);
		printf("Chaine de depart:     %s\n", argv[1]);
		printf("Caracteres a trimmer: %s\n\n", argv[2]);
		if (result)
		{
			printf("Resultat:             %s\n", result);
			printf("Taille: %zu\n", ft_strlen(result));
		}
		else
			printf("Erreur d'allocation memoire\n");
	}
	return (0);
}	
*/