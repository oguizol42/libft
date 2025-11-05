/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:12:59 by oguizol           #+#    #+#             */
/*   Updated: 2025/07/24 10:47:02 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*find_digi(char *str, int *sign)
{
	int	i;

	i = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	while (*str == '+' || *str == '-')
	{
		if (str[i] == '-')
			*sign = (*sign) * -1;
		++str;
	}
	return (str);
}

int	convert_to_digit(char *str)
{
	int	nbr;

	nbr = *str - '0';
	++str;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		nbr = nbr * 10 + (*str - '0');
		++str;
	}
	return (nbr);
}

int	ft_atoi(char *str)
{
	int		nbr;
	int		sign;
	char	*begin_dig;

	nbr = 0;
	sign = 1;
	begin_dig = find_digi(str, &sign);
	if (*begin_dig >= '0' && *begin_dig <= '9')
	{
		nbr = convert_to_digit (begin_dig);
		nbr = nbr * sign;
	}
	return (nbr);
}
/*
int	main (int n, char **str)
{
	int	nbr;
	
	nbr = 0;	
	if(n == 2)
		nbr = ft_atoi(str[1]);
	ft_putnbr(nbr);
	return (0);
}*/
