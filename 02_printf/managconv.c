/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:18:06 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/20 15:37:44 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	argtostr (va_list lstarg, t_strlist *lststr)
{
	
}

int	mconv (va_list lstarg, t_strlist *lststr)
{
	size_t	len;

	len = 0;
	if (!(lstarg && lststr && arg))
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
