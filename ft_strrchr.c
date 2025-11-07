/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:56:15 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/07 11:06:41 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while ((s[i] != '\0') && (s[i] != (unsigned char)c))
			++i;
		if (s[i] == (unsigned char)c)
			j = i;
		if (s[i] != '\0')
			++i;
	}
	if (s[j] == (unsigned char)c)
		return ((char *)(&s[j]));
	return (NULL);
}

/*
int	main(int argc, char **argv)
{
	char	*result;
	int		c;

	result = NULL;
	if (argc > 2)
	{
		c = *argv[2];
		printf("\nChaine: %s\nOccurence: %c\n", argv[1], c);
		result = ft_strrchr(argv[1], c);
		if (result != NULL)
			printf("Retour chaine occurence: %s\n", result);
		else
			printf("Occurence non trouvee\n");
	}
	return (0);
}
*/