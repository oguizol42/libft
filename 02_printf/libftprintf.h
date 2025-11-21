/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:46:00 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/21 16:26:41 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

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
size_t		mconv(va_list lstarg, t_strlist	*lststr);
size_t		ft_strlen(const char *s);
size_t		argtostr(va_list lstarg, t_strlist *lststr);
char		*ft_strdup(const char *s);
char		*ft_itoa(int n);
size_t		inttostr(va_list lstarg, t_strlist *lststr);
size_t		unsitostr(va_list lstarg, t_strlist *lststr);
char		*unsiitoa(unsigned int n);
int			ft_toupper(int c);
size_t		hexatostr(va_list lstarg, t_strlist *lststr);
char		*hextoa(unsigned int n);
int 		cntchhexa(unsigned int n);
char		*strtoupp(char *str);
#endif