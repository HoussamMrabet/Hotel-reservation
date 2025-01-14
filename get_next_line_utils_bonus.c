#include "get_next_line_bonus.h"

static size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (*(s + i))
	{
		if (*(s + i) == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	while (*(src + i))
	{
		*(dst + i) = *(src + i);
		i++;
	}
	return (*(dst + i) = '\0', dst);
}

char	*ft_strdup(char *s)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	return (ft_strcpy(str, s), str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (free(s1), NULL);
	return (ft_strcpy(str, s1), ft_strcpy(str + ft_strlen(s1), s2),
		free(s1), str);
}
