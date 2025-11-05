/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarthel <jbarthel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:30:46 by jbarthel          #+#    #+#             */
/*   Updated: 2025/07/28 18:59:41 by jbarthel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// Return 1 if character c is in string str. Else return 0.
int	is_in_str(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

// Return the number of non-null substrings of str.
// sep contains all the possible delimiters.
int	word_count(char *str, char *sep)
{
	int		count;
	char	prev_char;

	count = 0;
	prev_char = sep[0];
	while (*str)
	{
		if (is_in_str(*str, sep) && !is_in_str(prev_char, sep))
			count++;
		prev_char = *str;
		str++;
	}
	if (!(is_in_str(prev_char, sep)))
		count++;
	return (count);
}

char	*ft_strndup(char *src, int n)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc((n + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (i < n)
	{
		dup[i] = src[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}

// Return an array of strings where each string is a substring of str.
// charset is a string containing all the separator characters.
// The returned array is NULL-terminated.
char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*substr;
	int		substr_i;
	int		susbtr_nb;

	substr_i = 0;
	susbtr_nb = word_count(str, charset);
	result = (char **)malloc((susbtr_nb + 1) * sizeof(char *));
	substr = str;
	while (substr_i < susbtr_nb)
	{
		if (is_in_str(*str, charset) || *str == '\0')
		{
			if (str - substr != 0)
				result[substr_i++] = ft_strndup(substr, str - substr);
			while (is_in_str(*str++, charset) && *str != '\0')
				substr = str;
		}
		else
			str++;
	}
	result[substr_i] = NULL;
	return (result);
}
