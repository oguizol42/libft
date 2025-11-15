/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:17:12 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/05 17:28:10 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*
int	main(void)
{
	if (ft_isprint(31))
		write (1, "VRAI\n", 5);
	else
		write (1, "FAUX\n", 5);
	if (ft_isprint(32))
		write (1, "VRAI\n", 5);
	else
		write (1, "FAUX\n", 5);
	if (ft_isprint(' '))
		write (1, "VRAI\n", 5);
	else
		write (1, "FAUX\n", 5);
	if (ft_isprint(126))
		write (1, "VRAI\n", 5);
	else
		write (1, "FAUX\n", 5);
	if (ft_isprint(127))
		write (1, "VRAI\n", 5);
	else
		write (1, "FAUX\n", 5);
}
*/