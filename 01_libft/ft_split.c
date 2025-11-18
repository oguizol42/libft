/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:01:26 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/11 14:50:42 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cntspli(char const *s, char c)
{
	int	cnt;

	cnt = 0;
	if (s && *s != '\0')
	{
		if (c && c != '\0')
		{
			while (*s != '\0')
			{
				while (*s == c)
					++s;
				if (*s != '\0')
					++cnt;
				while ((*s != '\0') && (*s != c))
					++s;
			}
		}
		else
			++cnt;
	}
	return (cnt);
}

static void	fillarr(char **arr, char const *s, char c, int cnt)
{
	int	i;
	int	j;
	int	k;

	if (arr)
	{
		i = 0;
		j = 0;
		k = 0;
		while (i < cnt)
		{
			while ((s[j] != '\0') && (s[j] == c))
				++j;
			k = j;
			while ((s[k] != '\0') && (s[k] != c))
				++k;
			arr[i] = (char *)malloc(sizeof(char) * (k - j + 1));
			if (arr[i])
				ft_memcpy(arr[i], &s[j], (k - j + 1));
			arr[i][k - j] = '\0';
			j = k;
			++i;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		cnt;

	arr = NULL;
	cnt = cntspli(s, c);
	arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (arr)
	{
		fillarr (arr, s, c, cnt);
		arr[cnt] = NULL;
	}
	return (arr);
}

/*
int	main(int argc, char **argv)
{
	char	**array;

	array = NULL;
	if (argc > 2)
	{
		array = ft_split(argv[1], *argv[2]);
		printf("Chaine a spliter:          %s\n", argv[1]);
		printf("Caractere de delimitation: %c\n\n", *argv[2]);
		while (*array != NULL)
		{
			printf("%s\n", *array);
			++array;
		}
		if (!(*array))
			printf("NULL\n\n");
	}
	return (0);
}
*/