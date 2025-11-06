/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:33:07 by oguizol           #+#    #+#             */
/*   Updated: 2025/07/23 15:26:59 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = 0;
	while (src[i] != '\0')
		++i;
	copy = malloc (sizeof(char) * (i + 1));
	if (copy != NULL)
	{
		i = 0;
		while (src[i] != '\0')
		{
			copy[i] = src[i];
			++i;
		}
		copy[i] = '\0';
		return (copy);
	}
	return (NULL);
}
/*
void	ft_putstr(char *str)
{
	char	test;

	test = '\0';
	while ((*str) != test)
	{
		write(1, str, 1);
		++str;
	}
}

int	main (int argc, char **argv)
{
	char	*copy;

	copy = NULL;
	if (argc == 2)
	{
			copy = ft_strdup(argv[1]);
			ft_putstr(argv[1]);
			write (1, "\n", 1);
			ft_putstr(copy);
	}
	free (copy);
	copy = NULL;
	return (0);
}*/
