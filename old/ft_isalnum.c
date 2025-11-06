/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:44:24 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/05 16:57:48 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int	l = 1;

	while (l != EOF)
	{
		write (1, "Entrez un caractere: ", 21);
		l = getchar();
		if (ft_isalnum(l))
			write (1, "\nBien\n", 6);
		else
			write (1, "\nPas bien\n", 10);
		getchar();
	}
}
*/