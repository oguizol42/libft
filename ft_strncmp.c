/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:21:40 by oguizol           #+#    #+#             */
/*   Updated: 2025/07/17 20:54:34 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
	{
		++i;
	}
	if (i == n)
		--i;
	return (s1[i] - s2[i]);
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
	char	chaine1[] = "bonjour";
	char    chaine2[] = "bonsoir";
	//char    chaine3[] = "bon";
	
	if (ft_strncmp(chaine1, chaine2, 3) >= 0)
		ft_putnbr(ft_strncmp(chaine1, chaine2, 3));
	else
	{
		write(1, "-", 1);
		ft_putnbr(ft_strncmp(chaine1, chaine2, 3) * -1);
	}
	write (1, "\n", 2);
	
	if (ft_strncmp(chaine1, chaine2, 4) >= 0)
                ft_putnbr(ft_strncmp(chaine1, chaine2, 4));
        else
        {
                write(1, "-", 1);
                ft_putnbr(ft_strncmp(chaine1, chaine2, 4) * -1);
        }
        write (1, "\n", 2);

	return (0);
}*/
