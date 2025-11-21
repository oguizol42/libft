/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexatostring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:11:26 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/21 16:35:17 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	cntchhexa(unsigned int n)
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

char	*hextoa(unsigned int n)
{
	int		cnt;
	char	*str;

	cnt = cntchhexa(n);
	str = (char *)malloc(sizeof(char) * (cnt + 1));
	if (str)
	{
		str[cnt] = '\0';
		while (cnt > 0)
		{
			str[cnt - 1] = (n % 16);
			if ((n % 16) < 10)
				str[cnt - 1] += '0';
			else
				str[cnt - 1] = str[cnt - 1] - 10 + 'a';
			n /= 16;
			--cnt;
		}
	}
	return (str);
}

void	strtoupp(char *str)
{
	while (*str != '\0')
	{
		*str = ft_toupper(*str);
		++str;
	}
}

size_t	hexatostr(va_list lstarg, t_strlist *lststr)
{
	char			*str;
	unsigned int	n;

	str = NULL;
	n = 0;
	if ((((lststr->content)[1]) == 'x')
		|| (((lststr->content)[1]) == 'X'))
	{
		n = va_arg(lstarg, unsigned int);
		if (n == 0)
			str = ft_strdup("0");
		else
			str = hextoa(n);
		if (((lststr->content)[1]) == 'X')
			strtoupp(str);
		free (lststr->content);
		lststr->content = str;
		return (ft_strlen(str));
	}
	return (pointtostr(lstarg, lststr));
}
