/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointtostring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:49:51 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/24 08:49:52 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cntchpoint(unsigned long long n)
{
	int	cnt;

	cnt = 1;
	while (n / 16)
	{
		++cnt;
		n /= 16;
	}
	return (cnt);
}

char	*pointtoa(unsigned long long n)
{
	int		cnt;
	char	*str;

	cnt = cntchpoint(n);
	str = (char *)malloc(sizeof(char) * (cnt + 3));
	if (str)
	{
		str[cnt + 2] = '\0';
		while (cnt > 0)
		{
			str[cnt + 1] = (n % 16);
			if ((n % 16) < 10)
				str[cnt + 1] += '0';
			else
				str[cnt + 1] = str[cnt + 1] - 10 + 'a';
			n /= 16;
			--cnt;
		}
		str[0] = '0';
		str[1] = 'x';
	}
	return (str);
}

size_t	pointtostr(va_list lstarg, t_strlist *lststr)
{
	char				*str;
	unsigned long long	n;

	str = NULL;
	n = 0;
	if (((lststr->content)[1]) == 'p')
	{
		n = (unsigned long long)va_arg(lstarg, void *);
		if (n == 0)
			str = ft_strdup("(nil)");
		else
			str = pointtoa(n);
		free (lststr->content);
		lststr->content = str;
		return (ft_strlen(str));
	}
	return (0);
}
