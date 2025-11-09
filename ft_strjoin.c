#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*sconc;

	sconc = NULL;
	sconc = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if(sconc)
	{
		ft_strlcpy(sconc, s1, (ft_strlen(s1) + 1));
		ft_strlcat(sconc, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	}
	return (sconc);
}

/*
int	main(int argc, char **argv)
{
	char	*sconc;

	sconc = NULL;
	if (argc > 1)
	{
		printf("Chaine1: %s\n", argv[1]);
		printf("Chaine2: %s\n", argv[2]);
		sconc = ft_strjoin(argv[1], argv[2]);
		if (sconc)
			printf("\nChaine retour: %s\n", sconc);
		else
			printf("\nProbleme d'allocation\n");


	}
	return (0);
}
*/
