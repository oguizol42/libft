/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:47:33 by oguizol           #+#    #+#             */
/*   Updated: 2025/07/16 14:14:05 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		++str;
		++count;
	}
	return (count);
}
/*
int	puissance(int nbr, int puiss)
{
	int	result;

	result = nbr;
	if (puiss > 0)
	{
		while (puiss > 1)
		{
			result *= nbr;
			--puiss;
		}
	}
	else
		return (1);
	return (result);
}

int	compte(int nbr)
{
	int	compt;

	compt = 0;
	while (nbr / 10)
	{
		++compt;
		nbr /= 10;
	}
	return (compt);
}

void	ft_putnbr(int nb)
{
	char	aff;
	int		compt;
	int		div;
	int		nbrtmp;

	if (nb > 0)
	{
		compt = compte (nb);
		while (compt >= 0)
		{
			nbrtmp = nb;
			div = puissance (10, compt);
			nbrtmp = nb / div;
			aff = (nbrtmp % 10) + '0';
			write (1, &aff, 1);
			--compt;
		}
	}
	else
	{
		aff = 0 + '0';
		write (1, &aff, 1);
	}
}
int	main(void)
{
	char	print1[] = "abcdef";
	char    print2[] = "abc def";
	int	count;

	count = - 1;
	write (1, print1, 6);
	write (1, "\n", 2);
	count = ft_strlen(print1);
	ft_putnbr(count);
	write (1, "\n", 2);
	
	write (1, "\n", 2);
	write (1, print2, 6);
        write (1, "\n", 2);
        count = ft_strlen(print2);
	ft_putnbr(count);
        write (1, "\n", 2);
	return (0);
}*/
