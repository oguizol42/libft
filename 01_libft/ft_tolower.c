/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:30:52 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/07 10:39:42 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		c += (int)('a' - 'A');
	return (c);
}

/*
int	main(void)
{
	int	l;

	while (1)
	{
		printf("Taper une lettre: ");
		l = getchar();
		getchar();
		printf("%c\n", ft_tolower(l));
	}
	return (0);
}
*/