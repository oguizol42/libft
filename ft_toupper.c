#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		c -= (int)('a' - 'A');
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
		printf("%c\n", ft_toupper(l));
	}
	return (0);
}
*/
