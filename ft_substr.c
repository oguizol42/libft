/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:51:37 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/10 11:12:42 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!(s))
		return (NULL);
	if ((len > 0) && (start < ft_strlen(s)))
	{
		if (len > ft_strlen(&s[start]))
			len = ft_strlen(&s[start]);
	}
	else
		len = 0;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result)
	{
		ft_memcpy(result, &s[start], len);
		result[len] = '\0';
	}
	return (result);
}

/*
int	main(int argc, char **argv)
{
	unsigned int	start;
	size_t			len;
	char			*result;

	start = 0;
	len = 0;
	result = NULL;
	if (argc > 1)
	{
		printf("Chaine de caractere soumise:\n%s\n", argv[1]);
		printf("Longueur de la chaine: %zu\n", ft_strlen(argv[1]));
		printf("Choisissez l'index de depart: ");
		scanf("%d", &start);
		printf("\nChoisissez la longueur du substring: ");
		scanf("%zu", &len);
		result = ft_substr(argv[1], start, len);
		if (result)
			printf("\nSubstring retour:\n%s\n", result);
		else
			printf("\nProbleme rencontre lors de l'allocation memoire\n");
	}
	return (0);
}
*/
