/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:46:00 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/20 12:20:52 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct str_list
{
	char			*content;
	struct str_list	*next;
}	t_strlist;

void		readlst(t_strlist *lst);
int			ft_printf(const char *str, ...);
t_strlist	*init_node(char *content);
void		addnode(t_strlist **lst, char *str);
char		*recuparg(char **str, char *argcheck);
char		*recupstrcut(char **str);
void		freelst(t_strlist **lst);
char		*emptystr(void);
#endif
