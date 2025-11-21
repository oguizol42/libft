/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:18:06 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/21 16:28:20 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	unsitostr(va_list lstarg, t_strlist *lststr)
{
	char	*str;

	str = NULL;
	if (((lststr->content)[1]) == 'u')
	{
		str = unsiitoa(va_arg(lstarg, int));
		free (lststr->content);
		lststr->content = str;
		return (ft_strlen(str));
	}
	return (hexatostr(lstarg, lststr));
}

size_t	inttostr(va_list lstarg, t_strlist *lststr)
{
	char	*str;

	str = NULL;
	if (((lststr->content)[1] == 'i')
		|| ((lststr->content)[1] == 'd'))
	{
		str = ft_itoa(va_arg(lstarg, int));
		free (lststr->content);
		lststr->content = str;
		return (ft_strlen(str));
	}
	return (unsitostr(lstarg, lststr));
}

size_t	chartostr(va_list lstarg, t_strlist *lststr)
{
	char	c[2];
	char	*str;

	c[0] = (lststr->content)[1];
	c[1] = '\0';
	if ((c[0] == '%') || (c[0] == 'c'))
	{
		if (c[0] == 'c')
			c[0] = va_arg(lstarg, int);
		str = ft_strdup(c);
		free (lststr->content);
		lststr->content = str;
		return (ft_strlen(str));
	}
	return (inttostr(lstarg, lststr));
}

size_t	argtostr(va_list lstarg, t_strlist *lststr)
{
	char	*str;

	str = NULL;
	if (ft_strlen(lststr->content) >= 2)
	{
		if (((lststr->content)[1]) == 's')
		{
			str = ft_strdup(va_arg(lstarg, char *));
			if (str)
			{
				free (lststr->content);
				lststr->content = str;
				return (ft_strlen(lststr->content));
			}
		}
		return (chartostr(lstarg, lststr));
	}
	return (0);
}

size_t	mconv(va_list lstarg, t_strlist *lststr)
{
	size_t	len;

	len = 0;
	if (!(lstarg && lststr))
		return (0);
	len = ft_strlen(lststr->content);
	lststr = lststr->next;
	while (lststr)
	{
		if (lststr->content)
			argtostr (lstarg, lststr);
		len += ft_strlen(lststr->content);
		lststr = lststr->next;
		if (lststr)
		{
			len += ft_strlen(lststr->content);
			lststr = lststr->next;
		}
	}
	return (len);
}
