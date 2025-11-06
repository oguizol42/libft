#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		c += (int)('a' - 'A');
	return (c);
}

/*
int	main()
{
	int	l;

	while (1)
	{
		printf("Taper une lettre: ");
		l = getchar();
		getchar();
		printf("%c\n", ft_tolower(l));
	}
	return (0);
}
*/
