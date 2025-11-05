/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:32:13 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/04 15:25:24 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	int	l = 1;

	while(l != EOF)
	{
		write (1, "Entrez une lettre: ", 19);
		l = getchar();
		if (ft_isalpha(l))
			write (1, "\nAlphanumerique\n", 16);
		else
			write (1, "\nPas alphanumerique\n", 20);
		getchar();
	}
}
*/
/* //OLD CODE
	unsigned char	test;

	test = (unsigned char) c;
	if (c == EOF || c < 0 || c > 255
		|| !((test >= 'a' && test <= 'z')
			|| (test >= 'A' && test <= 'Z')))
		return (0);
	return (1);
	*/