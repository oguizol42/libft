#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dupli;
	int		i;

	i = 0;
	while (s[i] != '\0')
		++i;
	dupli = malloc (sizeof(char) * (i + 1));
	if (dupli)
	{
		i = 0;
		while (s[i] != '\0')
		{
			dupli[i] = s[i];
			++i;
		}
		dupli[i] = '\0';
	}
	else
		errno = ENOMEM;
	return (dupli);
}

/*
int	main(int argc, char **argv)
{
	char	*dupli;
	
	dupli = NULL;
	if (argc > 1)
	{
		printf("Chaine source:    %s\n", argv[1]);
		dupli = ft_strdup(argv[1]);
		if (dupli)
			printf("Chaine dupliquee: %s\n", dupli);
		else if (errno == ENOMEM)
			printf("Pas assez d'espace memoire pour la duplication");
		else
			printf("Duplication echouee\n");
	}
	free (dupli);
	return (0);
}
*/
