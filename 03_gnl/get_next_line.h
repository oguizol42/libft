/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:25:18 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/25 16:30:20 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 25
#endif

#include <unistd.h>
#include <stdlib.h>

struct typedef s_lststash
{
	int			fd;
	char		*stash;
	t_lststash	*next;
}	t_lststash;

char	*get_next_line(int fd);

#endif
