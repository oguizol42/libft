#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	char	*s1trim;
	size_t	sizeset;
	size_t	i;
	size_t	start;
	size_t	end;

	sizeset = ft_strlen(set);
	start = 0;
	end = ft_strlen(s1) - 1;
	s1trim = NULL;
	if (sizeset)
	{
		i = 0;
		while (i < sizeset)
		{
			while((ft_strchr(s1, set[i]) != s1) && (i < sizeset))
				++i;
			if ((i < sizeset) && (s1[start] != '\0'))
			{
				++i;
				++start;
			}
		}
		i = 0;
		while (i < sizeset)
		{
			while((ft_strrchr(s1, set[i]) != &s1[end]) && (i < sizeset))
				++i;
			if ((i < sizeset) && (end > 0))
			{
				++i;
				--end;
			}
		}
		if (end <= start)
			if (s1trim = malloc(sizeof(char)))
				*s1trim = '\0';
		if (s1trim = malloc(sizeof(char) * (end - start) + 2))
		{
			ft_memcpy(s1trim, &s1[start], (end - start + 1));
			s1trim[end - start + 1] = '\0';
		}
	}
	return (s1trim);
}
