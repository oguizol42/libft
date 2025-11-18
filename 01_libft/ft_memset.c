/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:14:14 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/09 17:56:58 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*chg;
	size_t			i;

	i = 0;
	chg = s;
	while (i < n)
	{
		chg[i] = (unsigned char)c;
		++i;
	}
	return (s);
}

/*
int	main(void)
{
	void	*b;
	int		i;
	char	a[] = "Salut TA";

	i = 0;
	printf ("\nAvant: %s", a);
	b = ft_memset(a, 'F', 3);
	printf ("\nApres: %s", (char *)b);
	return (0);
}
*/
