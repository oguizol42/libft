/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:08:16 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/21 13:26:29 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	countch(int n)
{
	int	cnt;

	cnt = 1;
	if (n < 0)
		n *= -1;
	while (n / 10)
	{
		++cnt;
		n /= 10;
	}
	return (cnt);
}

static char	*allocalpha(int n, int cnt)
{
	char	*alpha;

	alpha = NULL;
	if (cnt)
	{
		if (n < 0)
		{
			alpha = (char *)malloc(sizeof(char) * (cnt + 2));
			*alpha = '-';
		}
		else
			alpha = (char *)malloc(sizeof(char) * (cnt + 1));
		if (alpha)
		{
			if (n >= 0)
				alpha[cnt] = '\0';
			else
				alpha[cnt + 1] = '\0';
		}
	}
	return (alpha);
}

static int	convtoa(int n, char *alpha, int cnt)
{
	int	div;
	int	pos;

	div = 1;
	pos = 0;
	if (n && alpha && cnt)
	{
		while (cnt > 1)
		{
			div *= 10;
			--cnt;
		}
		while (div > 0)
		{
			alpha[pos] = (n / div) + '0';
			n %= div;
			++pos;
			div /= 10;
		}
		return (1);
	}
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char	*alpha;
	int		cnt;
	int		result;

	alpha = NULL;
	result = 0;
	cnt = countch(n);
	alpha = allocalpha(n, cnt);
	if (n > 0)
		result = convtoa(n, alpha, cnt);
	if (n == INT_MIN)
	{
		result = convtoa(-(n + 1), &alpha[1], cnt);
		alpha[cnt] += 1;
	}
	if ((n < 0) && (n != INT_MIN))
		result = convtoa(-n, &alpha[1], cnt);
	if (n == 0)
	{
		*alpha = '0';
		result = 1;
	}
	if (result)
		return (alpha);
	return (NULL);
}

/*
int	main(void)
{
	int	nbr;

	nbr = 0;
	printf("Entrez un nombre: ");
	scanf("%d", &nbr);
	printf("\nChaine en sortie: %s", ft_itoa(nbr));
	return (0);
}
*/