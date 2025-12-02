/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:57:45 by oguizol           #+#    #+#             */
/*   Updated: 2025/12/02 19:48:02 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_line
{
	int				fd;
	char			*stash;
	char			*line;
	struct s_line	*next;
}			t_line;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
void	get_line_fd(t_line *line);
int		cutline(t_line *line, char *readfd, int len);
void	deltline(t_line **lst, t_line *tofree);
t_line	*get_node(t_line **lst, int fd);
t_line	*init_node(int fd);
#endif