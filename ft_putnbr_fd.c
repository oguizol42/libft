/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:59:25 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/13 14:45:24 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == 0)
		c = '0';
	if (n > 0)
	{
		if (n / 10)
			ft_putnbr_fd((n / 10), fd);
		c = (n % 10) + '0';
	}
	if (n < 0)
	{
		write (fd, "-", 1);
		if (n == INT_MIN)
		{
			ft_putnbr_fd((INT_MAX / 10), fd);
			c = ((INT_MAX) % 10) + 1 + '0';
		}
		else
		{
			if ((-n) / 10)
				ft_putnbr_fd(-(n / 10), fd);
			c = ((-n) % 10) + '0';
		}
	}
	write (fd, &c, 1);
}

/*
#include <stdio.h>
int	main(void)
{
	int	n;

	printf("Choisissez un nombre: ");
	scanf("%d");
	printf("Chaine retour: %s", ft_putchar_fd(n, 1);
	return (0);
}
*/
