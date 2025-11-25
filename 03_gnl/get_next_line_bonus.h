/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:13:28 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/25 20:32:42 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 25
# endif

# include <unistd.h>
# include <stdlib.h>

struct typedef s_lststash
{
	int			fd;
	int			endofi;
	char		*stash;
	t_lststash	*next;
}	t_lststash;

char		*get_next_line(int fd);
void		initnode(int fd, t_lststash **node);
void		delnode(t_lststash *list, t_lststash *node);
void		addnode(t_lststash *list, t_lststash *poslist);
char		*doread(t_lststash *list, t_lststash *node);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*strcut(t_lststash *list, t_lststash *node, char *strj);

#endif