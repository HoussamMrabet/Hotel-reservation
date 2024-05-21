#include "hotel.h"

static	int	count_words(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (*(s + i))
	{
		while (*(s + i) && *(s + i) == c)
			i++;
		if (*(s + i) && *(s + i) != c)
			count++;
		while (*(s + i) && *(s + i) != c)
			i++;
	}
	return (count);
}

static int	ft_getlen(const char *src, char c)
{
	int	i;

	i = 0;
	while (*(src + i) != c && *(src + i) != '\0')
		i++;
	return (i);
}

static	char	**fill(char **res, const char *s, char c, int i)
{
	int	j;

	j = 0;
	while (*(s + j))
	{
		while (*(s + j) == c)
			j++;
		if (*(s + j))
		{
			res[i] = (char *)malloc(ft_getlen((s + j), c) + 1);
			if (!res[i])
			{
				while (i > 0)
					free(res[--i]);
				free(res);
				return (NULL);
			}
			ft_strlcpy(*(res + i), s + j, ft_getlen((s + j), c) + 1);
			i++;
			j += ft_getlen((s + j), c);
		}
	}
	*(res + i) = NULL;
	return (res);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	char	**res;

	i = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(8 * (count_words((char *)s, c) + 1));
	if (!res)
		return (NULL);
	res = fill(res, s, c, i);
	return (res);
}