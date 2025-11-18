/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:53:39 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/07 20:46:01 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	sign;
	int	i;

	sign = 1;
	nbr = 0;
	i = 0;
	while ((nptr[i] == ' ') || ((nptr[i] >= 9) && (nptr[i] <= 13)))
		++i;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		++i;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		nbr = (10 * nbr) + (nptr[i] - '0');
		++i;
	}
	return (nbr * sign);
}

/*
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("\nChaine envoyee: %s\n", argv[1]);
		printf("Valeur de retour: %d\n", (ft_atoi(argv[1])));
	}
	return (0);
}
*/