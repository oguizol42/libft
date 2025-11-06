/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:05:33 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/05 14:19:43 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
int	main(void)
{
	int	l = 1;

	while (l != EOF)
	{
		write (1, "Entrez un chiffre: ", 19);
		l = getchar();
		if (ft_isdigit(l))
			write (1, "\nNumerique\n", 11);
		else
			write (1, "\nPas numerique\n", 15);
		getchar();
	}
}
*/