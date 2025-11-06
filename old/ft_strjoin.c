/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:32:45 by oguizol           #+#    #+#             */
/*   Updated: 2025/07/24 19:16:32 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		++i;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i + 1] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	char	test;
	int		count;

	count = 0;
	test = '\0';
	if ((*str) != test)
	{
		while ((*str) != test)
		{
			++count;
			++str;
		}
	}
	return (count);
}

void	multi_cat(int size, char *cat, char **strs, char *sep)
{
	int	i;

	i = 0;
	cat[0] = '\0';
	while (i < (size - 1))
	{
		ft_strcat(cat, strs[i]);
		ft_strcat(cat, sep);
		++i;
	}
	ft_strcat(cat, strs[size - 1]);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*cat;
	int		size_total;
	int		i;

	cat = NULL;
	if (size == 0)
	{
		cat = malloc (sizeof(char));
		*cat = '\0';
		return (cat);
	}
	i = 0;
	size_total = ((size - 1) * ft_strlen (sep)) + 1;
	while (i < size)
	{
		size_total += ft_strlen(strs[i]);
		++i;
	}
	cat = malloc (sizeof(char) * size_total);
	if (cat)
		multi_cat (size, cat, strs, sep);
	return (cat);
}
/*
int	main(int argc, char **argv)
{
	char	*ret;

	ret = NULL;
	if (argc > 1)
	{
		print_strs_test((argc - 1), &argv[1], " ,???..., ");
		ret = ft_strjoin((argc - 1), &argv[1], " ,???..., ");
	}
	if (ret)
	{
		write (1, "\nChaine retournee :\n", 20);
		ft_putstr(ret);
	}

	free (ret);
	return (0);
}*/
