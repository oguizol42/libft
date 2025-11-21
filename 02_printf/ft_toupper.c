/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:30:30 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/07 10:41:09 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		c -= (int)('a' - 'A');
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
		printf("%c\n", ft_toupper(l));
	}
	return (0);
}
*/