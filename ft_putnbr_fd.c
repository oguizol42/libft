/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:59:25 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/11 20:25:07 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*send;

	send = ft_itoa(n);
	while (*send != '\0')
	{
		write (fd, send, 1);
		++send;
	}
	write (fd, "\0", 1);
}
