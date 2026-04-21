
#include "pushswap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int			i;

	i = 0;
	c = (unsigned char )c;
	while (s[i])
	{
		if (s[i] == c)
		{
			return ((char *)(&s[i]));
		}
		i++;
	}
	if (c == 0)
		return ((char *)(&s[i]));
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		p;

	i = 0;
	p = 0;
	if (!s1)
		return (NULL);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i])
	{
		ptr[p] = s1[i];
		i++;
		p++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[p++] = s2[i++];
	}
	ptr[p] = 0;
	return (ptr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
