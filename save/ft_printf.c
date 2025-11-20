/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:44:43 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/20 12:21:22 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	readlst(t_strlist *lst)
{
	char	*str;

	str = NULL;
	while (lst)
	{
		str = lst->content;
		while (str && *str != '\0')
		{
			write(1, str, 1);
			++str;
		}
		lst = lst->next;
	}
}

int	ft_printf(const char *str, ...)
{
	t_strlist	*lststr;
	char		*strcpy;
	char		*strrecup;

	strcpy = (char *)str;
	lststr = NULL;
	strrecup = NULL;
	while (strcpy && (*strcpy != '\0'))
	{
		strrecup = recupstrcut(&strcpy);
		addnode(&lststr, strrecup);
		strrecup = recuparg(&strcpy, "cspdiuxX%");
		addnode(&lststr, strrecup);
		//TEMPO
		if (!strrecup && *strcpy != '\0')
		{
			write (1, "PRESENCE D'ARGUMENT INVALIDE DANS LA CHAINE\n", 44);
			strcpy = NULL;
			return (0);
		}
		//
	}
	readlst(lststr);
	freelst(&lststr);
	return (0);
}

int	main(int argc, char **argv)
{
	//char	*strcut;
	//int	i;

	if (argc <= 1)
		return (0);
	ft_printf(argv[1]);
	/*
	while (*argv[1] != '\0')
	{
		strcut = recupstrcut(&argv[1]);
		if (strcut)
		{
			write (1, "\n\n", 2);
			while (strcut && *strcut != '\0')
			{
				write (1, strcut, 1);
				++strcut;
			}
			write(1, "\n", 1);
			i = 0;
			while (argv[1][i] != '\0')
					{
							write (1, &(argv[1][i]), 1);
				++i;
					}
		}
		else
			return (0);
		write (1, "\n", 1);
		strcut = recuparg(&argv[1], "cspdiuxX%");
			if (strcut)
			{
					while (strcut && *strcut != '\0')
					{
							write (1, strcut, 1);
				++strcut;
					}
					write (1, "\n", 1);
			i = 0;
			while (argv[1][i] != '\0')
			{
				write (1, &(argv[1][i]), 1);
				++i;
			}
			}
		else
			return (0);
		write (1, "\n\n", 2);
	}*/
	return (0);
}


/*
CONVERSIONS POSSIBLES: 

•%c Prints a single character.
•%s Prints a string (as defined by the common C convention).
•%p The void * pointer argument has to be printed in hexadecimal format.
•%d Prints a decimal (base 10) number.
•%i Prints an integer in base 10.
•%u Prints an unsigned decimal (base 10) number.
•%x Prints a number in hexadecimal (base 16) lowercase format.
•%X Prints a number in hexadecimal (base 16) uppercase format.
•%% Prints a percent sign.

Fonctions de creations de chaines
- %c principe du putchar()
- %s ft_strjoin()
- %i et %d meme fonction (reprendre le principe de ft_putnbr)




- 
- Une fonction d'analyse d'argument retourne chaque chaine de caractere voulu a printf()
- Stockage des chaines au fur et a mesure dans une liste chainee
- Affichage de chaque chaine de la liste chainee avec retour du nombre de caractere ou -1 si echoue
*/
