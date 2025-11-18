/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:17:31 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/06 09:43:40 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*chg;

	chg = s;
	while (n > 0)
	{
		*chg = '\0';
		++chg;
		--n;
	}
}

/*
int	main(void)
{
	int		i;
	char	a[] = "Salut TA";

	i = 0;
	printf ("\nAvant: %s", a);
	ft_bzero(a, 3);
	printf ("\nApres du debut de la chaine: %s", &a[0]);
	printf ("\nApres a partir du deuxieme caractere: %s", &a[1]);
	printf ("\nApres a partir du troisieme caractere: %s", &a[2]);
	printf ("\nApres a partir du quatrieme caractere: %s", &a[3]);
	return (0);
}
*/