/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:46:30 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/21 11:02:51 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*dupli;
	int		i;

	i = 0;
	while (s[i] != '\0')
		++i;
	dupli = malloc (sizeof(char) * (i + 1));
	if (dupli)
	{
		i = 0;
		while (s[i] != '\0')
		{
			dupli[i] = s[i];
			++i;
		}
		dupli[i] = '\0';
	}
	return (dupli);
}

/*
int	main(int argc, char **argv)
{
	char	*dupli;
	
	dupli = NULL;
	if (argc > 1)
	{
		printf("Chaine source:    %s\n", argv[1]);
		dupli = ft_strdup(argv[1]);
		if (dupli)
			printf("Chaine dupliquee: %s\n", dupli);
		else if (errno == ENOMEM)
			printf("Pas assez d'espace memoire pour la duplication");
		else
			printf("Duplication echouee\n");
	}
	free (dupli);
	return (0);
}
*/
