/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:59:42 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/05 17:16:32 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
int	main(void)
{
	if (ft_isascii(-5))
		write (1, "VRAI\n", 5);
	else
		write (1, "FAUX\n", 5);
	if (ft_isascii(0))
		write (1, "VRAI\n", 5);
	else
		write (1, "FAUX\n", 5);
	if (ft_isascii(5))
		write (1, "VRAI\n", 5);
	else
		write (1, "FAUX\n", 5);
	if (ft_isascii('A'))
		write (1, "VRAI\n", 5);
	else
		write (1, "FAUX\n", 5);
}
*/