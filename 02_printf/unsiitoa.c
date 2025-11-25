/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsiitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:26:16 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/24 09:16:10 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	countch(unsigned int n)
{
	int	cnt;

	cnt = 1;
	while (n / 10)
	{
		++cnt;
		n /= 10;
	}
	return (cnt);
}

static char	*allocalpha(unsigned int cnt)
{
	char	*alpha;

	alpha = NULL;
	if (cnt)
	{
		alpha = (char *)malloc(sizeof(char) * (cnt + 1));
		if (alpha)
			alpha[cnt] = '\0';
	}
	return (alpha);
}

static unsigned int	convtoa(unsigned int n, char *alpha, unsigned int cnt)
{
	unsigned int	div;
	unsigned int	pos;

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

char	*unsiitoa(unsigned int n)
{
	char				*alpha;
	unsigned int		cnt;
	unsigned int		result;

	alpha = NULL;
	result = 0;
	cnt = countch(n);
	alpha = allocalpha(cnt);
	if (n > 0)
		result = convtoa(n, alpha, cnt);
	if (n == 0)
	{
		*alpha = '0';
		result = 1;
	}
	if (result)
		return (alpha);
	return (NULL);
}
