/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:44:43 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/21 15:02:15 by oguizol          ###   ########.fr       */
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
	va_list		lstarg;
	char		*strcpy;
	char		*strrecup;
	int			len;

	strcpy = (char *)str;
	lststr = NULL;
	if (!str || (*str == '\0'))
		return (0);
	while (strcpy && (*strcpy != '\0'))
	{
		strrecup = recupstrcut(&strcpy);
		addnode(&lststr, strrecup);
		strrecup = recuparg(&strcpy, "cspdiuxX%");
		addnode(&lststr, strrecup);
		if (!strrecup && *strcpy != '\0')
			return (0);
	}
	va_start (lstarg, str);
	len = mconv (lstarg, lststr);
	va_end (lstarg);
	readlst(lststr);
	freelst(&lststr);
	return (len);
}


#include <stdio.h>

int	main (void)
{
	int	count;
	int	count2;

	count = 0;
	count2 = 1275;
	
	count = ft_printf("Salut Ta%s, ca %ca T%a ?%% %i - %d", "Oui Ta ?", 'v', count2, count2);
	write (1, "\n", 1);
	//count2 = printf("Salut Ta%s, ca %ca T%a ?%%", "Oui Ta ?", 'v');
	
	printf("\n\n\nTaille de la chaine ft_printf: %d\n", count);
	printf("\n\n\nTaille de la chaine    printf: %d\n", count2);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	int	count;
	int count2;

	count = 0;
	count2 = 0;
	if (argc <= 1)
		return (0);
	if (argc == 2)
	{
		count = ft_printf(argv[1]);
		write (1, "\n", 1);
		count2 = printf("%s", argv[1]);
	}
	else
	{
		count = ft_printf(argv[1], argv[2]);
		write (1, "\n", 1);
		count2 = printf(argv[1], argv[2]);
	}
	printf("\n\n\nTaille de la chaine ft_printf: %d\n", count);
	printf("\n\n\nTaille de la chaine    printf: %d\n", count2);
	return (0);
}*/


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


restant a gerer: p x X"

*/
