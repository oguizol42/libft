/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:55:00 by oguizol           #+#    #+#             */
/*   Updated: 2025/07/31 20:54:12 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < (size - 1))
		++i;
	while (src[j] != '\0' && i < (size - 1))
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = '\0';
	return (i);
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

void	ft_putstr(char *str)
{
	char	test;

	test = '\0';
	while ((*str) != test)
	{
		write(1, str, 1);
		++str;
	}
}
int	main(void)
{
	unsigned int	retour;
	char	chaine1[100] = "Salut ";
	char	chaine2[100] = "les copains !!!!!";
	char	chaine3[100] = " Comment vas ?";

	ft_putstr(chaine1);
	write (1, "\n", 2);
	ft_putstr(chaine3);
        write (1, "\n", 2);
	retour = ft_strlcat(chaine1, chaine3, 100);
	ft_putnbr(retour);	
        write (1, "\n", 2);
	ft_putstr(chaine1);
        write (1, "\n", 2);
        ft_putstr(chaine3);
        write (1, "\n", 2);
	write (1, "\n", 2);

	ft_putstr(chaine1);
        write (1, "\n", 2);
        ft_putstr(chaine2);
        write (1, "\n", 2);
        retour = ft_strlcat(chaine1, chaine2, 5);
        ft_putnbr(retour);
        write (1, "\n", 2);
        ft_putstr(chaine1);
        write (1, "\n", 2);
        ft_putstr(chaine2);
        write (1, "\n", 2);
        write (1, "\n", 2);

	ft_putstr(chaine1);
        write (1, "\n", 2);
        ft_putstr(chaine3);
        write (1, "\n", 2);
        retour = ft_strlcat(chaine1, chaine3, 100);
        ft_putnbr(retour);
        write (1, "\n", 2);
        ft_putstr(chaine1);
        write (1, "\n", 2);
        ft_putstr(chaine3);
        write (1, "\n", 2);
        write (1, "\n", 2);
	return (0);
}*/
