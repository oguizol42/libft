/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:03:39 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/28 16:39:04 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 48
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_lstfd
{
	int				fd;
	char			*stash;
	int				endofi;
	struct s_lstfd	*next;
}							t_lstfd;

char	*get_next_line(int fd);
t_lstfd	*addnode(t_lstfd *list, int fd);

#endif
