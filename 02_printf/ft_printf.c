#include "libftprintf.h"

static char	*recuparg(char **str, char *argcheck)
{
	char	*new;

	new = NULL;
	if (!str || !(*str) || **str != '%' || **str == '\0')
		return (NULL);
	while ((*argcheck != '\0') && ((*str)[1] != *argcheck))
		++argcheck;
	if (*argcheck != '\0')
	{
		new = (char *)malloc(sizeof(char) * 3);
		new[0] = (*str)[0];
		new[1] = (*str)[1];
		new[2] = '\0';
		*str = &((*str)[2]);
	}
	return (new);
}

static char	*recupstrcut(char **str)
{
	char	*new;
	int	end;
	int	i;

	new = NULL;
	end = 0;
	i = 0;
	if (!str || !(*str))
		return (NULL);
	while((*str)[end] != '\0' && (*str)[end] != '%')
		++end;
	new = (char *)malloc(sizeof(char) * (end + 1));
	if (!new)
		return (NULL);
	while (i < end)
	{
		new[i] = (*str)[i];
		++i;
	}
	new[i] = '\0';
	*str = &((*str)[i]);
	return (new);
}
/*
static t_list	*creatlist(char *str)
{
	t_list	*strlist;
	t_list	*strlistpos;
	char	*strcut;

	strlist = NULL;
	strlistpos = NULL;
	strcut = NULL;
	while(str && *str != '\0')
	{
		strcut = recupstrcut(&str);

		/*
		if (!strcut)
		{
			//destruction liste chainee
			//return (-1);
		}
		strlistpos = ft_lstnew(strcut);
		if(!strlistpos)
		{
			//fonction de destruction de la liste chainee a creer
			return (-1);
		}
		if (!strlist)
			strlist = strlistpos;
		else
			ft_lstadd_back(&strlist, strlistpos);
	}
	return (strlist);
}

int	ft_printf(const char *str, ...)
{
	va_list	ps;
	t_list	*strlist;

	strlist = NULL;
	//strlist = creatlist(str);
}
*/
int	main(int argc, char **argv)
{
	char	*strcut;
	int	i;

	if (argc <= 1)
		return (0);
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
	}
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
