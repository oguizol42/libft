/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:59:25 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/13 14:45:24 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*send;
	char	*ptr;

	ptr = ft_itoa(n);
	if (ptr)
	{
		send = ptr;
		while (*send != '\0')
		{
			write (fd, send, 1);
			++send;
		}
		free(ptr);
	}
}

