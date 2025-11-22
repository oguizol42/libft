/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 08:43:56 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/20 12:22:17 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*emptystr(void)
{
	char	*empty;

	empty = (char *)malloc(sizeof(char));
	if (empty)
		*empty = '\0';
	return (empty);
}

char	*recuparg(char **str, char *argcheck)
{
	char	*new;

	new = emptystr();
	if (!str || !(*str))
		return (NULL);
	if (**str != '%' || **str == '\0')
		return (new);
	while ((*argcheck != '\0') && ((*str)[1] != *argcheck))
		++argcheck;
	if (*argcheck == '\0')
	{
		++(*str);
		return (new);
	}
	free (new);
	new = (char *)malloc(sizeof(char) * 3);
	new[0] = (*str)[0];
	new[1] = (*str)[1];
	new[2] = '\0';
	*str = &((*str)[2]);
	return (new);
}

char	*recupstrcut(char **str)
{
	char	*new;
	int		end;
	int		i;

	new = NULL;
	end = 0;
	i = 0;
	if (!str || !(*str))
		return (NULL);
	while ((*str)[end] != '\0' && (*str)[end] != '%')
		++end;
	new = (char *)malloc(sizeof(char) * (end + 1));
	if (!new)
		return (NULL);
	while (i < end)
	{
		new[i] = (*str)[i];
		++i;
	}
	new[i] = '\0';
	*str = &((*str)[i]);
	return (new);
}
