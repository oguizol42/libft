/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:49:23 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/20 15:19:22 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		++s;
		++count;
	}
	return (count);
}

/*
int	main(int argc, char **argv)
{
	if (argc > 1)
		printf("%zu\n", ft_strlen(argv[1]));
	return (0);
}
*/