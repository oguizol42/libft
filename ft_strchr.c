#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((s[i] != '\0') && (s[i] != (unsigned char)c))
		++i;
	if (s[i] == (unsigned char)c)
		return ((char *)(&s[i]));
	return (NULL);
}

/*
int	main(int argc, char **argv)
{
	int	c;
	char	*result;

	result = NULL;
	if (argc > 2)
	{
		c = *argv[2];
		printf("\nChaine: %s\nOccurence: %c\n", argv[1], c);
		result = ft_strchr(argv[1], c);
		if (result != NULL)
			printf("Retour chaine occurence: %s\n", result);
		else
			printf("Occurence non trouvee\n");
	}
	return (0);
}
*/
