/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 10:46:30 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/24 08:48:40 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*dupli;
	int		i;

	i = 0;
	while (s[i] != '\0')
		++i;
	dupli = malloc (sizeof(char) * (i + 1));
	if (dupli)
	{
		i = 0;
		while (s[i] != '\0')
		{
			dupli[i] = s[i];
			++i;
		}
		dupli[i] = '\0';
	}
	return (dupli);
}
