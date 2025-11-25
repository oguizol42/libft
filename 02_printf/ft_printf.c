/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oguizol <oguizol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:44:43 by oguizol           #+#    #+#             */
/*   Updated: 2025/11/24 10:09:31 by oguizol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	readlst(t_strlist *lst)
{
	char	*str;
	int		result;

	str = NULL;
	result = 0;
	while (lst)
	{
		str = lst->content;
		if ((lst->state) == 's')
		{
			while (str && *str != '\0')
			{
				result = write(1, str, 1);
				if (result == -1)
					return (result);
				++str;
			}
		}
		else
			write (1, str, 1);
		lst = lst->next;
	}
	return (1);
}

int	checkstr(char **str, t_strlist **lststr)
{
	char		*strrecup;

	strrecup = NULL;
	strrecup = recupstrcut(str);
	addnode(lststr, strrecup);
	strrecup = recuparg(str, "cspdiuxX%");
	addnode(lststr, strrecup);
	if (!strrecup && **str != '\0')
		return (-1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	t_strlist	*lststr;
	va_list		lstarg;
	char		*strcpy;
	int			len;

	strcpy = (char *)str;
	lststr = NULL;
	if (!str || (*str == '\0'))
		return (0);
	while (strcpy && (*strcpy != '\0'))
	{
		if (checkstr(&strcpy, &lststr) == -1)
			return (-1);
	}
	va_start (lstarg, str);
	len = mconv (lstarg, lststr);
	va_end (lstarg);
	if (readlst(lststr) == -1)
		return (-1);
	freelst(&lststr);
	return (len);
}

/*
#include <stdio.h>

int	main (void)
{
	int		count;
	int		count2;
	int 	nbr;
	char	*str = "Salut Ta";

	count = 0;
	count2 = 1275;
	nbr = 254;
	
	count = ft_printf("Salut Ta%s, ca %ca T%a ?%% %i - %d", "Oui Ta ?", 'v', count2, count2);
	write (1, "\n", 1);
	//count2 = printf("Salut Ta%s, ca %ca T%a ?%%", "Oui Ta ?", 'v');
	
	printf("\n\n\nTaille de la chaine ft_printf: %d\n", count);
	printf("\n\n\nTaille de la chaine    printf: %d\n", count2);

	count = ft_printf("Affichage du nombre %d ou %i en hexadecimal: %x ou %X", nbr, nbr, nbr, nbr);
	write (1, "\n", 1);
	count2 = printf("Affichage du nombre %d ou %i en hexadecimal: %x ou %X", nbr, nbr, nbr, nbr);
	
	printf("\n\n\nTaille de la chaine ft_printf: %d\n", count);
	printf("\n\n\nTaille de la chaine    printf: %d\n", count2);

	nbr = -120;
	count = ft_printf("Affichage du nombre %d ou %i en hexadecimal: %x ou %X", nbr, nbr, nbr, nbr);
	write (1, "\n", 1);
	count2 = printf("Affichage du nombre %d ou %i en hexadecimal: %x ou %X", nbr, nbr, nbr, nbr);
	
	printf("\n\n\nTaille de la chaine ft_printf: %d\n", count);
	printf("\n\n\nTaille de la chaine    printf: %d\n", count2);

	count = ft_printf("Affichage adresse pointeur %s en hexadecimal: %p", str, str);
	write (1, "\n", 1);
	count2 = printf("Affichage adresse pointeur %s en hexadecimal: %p", str, str);
	
	printf("\n\n\nTaille de la chaine ft_printf: %d\n", count);
	printf("\n\n\nTaille de la chaine    printf: %d\n", count2);


	count = ft_printf(" NULL %s NULL ", NULL);
	write (1, "\n", 1);
	//count2 = printf(" NULL %s NULL ", NULL);
	
	printf("\n\n\nTaille de la chaine ft_printf: %d\n", count);
	printf("\n\n\nTaille de la chaine    printf: %d\n", count2);
	return (0);
}*/
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


restant a gerer: p"

*/
