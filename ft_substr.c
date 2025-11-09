/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:51:37 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/09 19:35:14 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	pos;
	
	pos = 0;
	result = NULL;
	if (len > 0)
		result = (char *)malloc(sizeof(char) * (len + 1));
	if (result)
	{
		while ((pos < len) && (s[start + pos] != '\0'))
		{
			result[pos] = s[start + pos];
			++pos;
		}
		result[pos] = '\0';
	}
	return (result);
}

/*
int	main(void)
{
	return (0);
}
*/