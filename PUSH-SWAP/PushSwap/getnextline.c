
#include "pushswap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (s1[i] - s2[i]);
}

static void	allocation(char **stored, char **allocated)
{
	if (!*stored)
	{
		*stored = ft_strdup("");
		if (!*stored)
			*stored = NULL;
	}
	*allocated = malloc((size_t)BUFFER_SIZE + 1);
	if (!*allocated)
	{
		if (*stored)
			free(*stored);
		*stored = NULL;
	}
}

static void	fireforce(char **stored, char **allocated)
{
	free(*stored);
	*stored = NULL;
	free(*allocated);
	allocated = NULL;
}

static char	*returned_line(char **stored, int readen)
{
	char	*temp_saved;
	char	*pos;

	if (readen > 0)
	{
		temp_saved = *stored;
		pos = ft_strchr(temp_saved, '\n');
		*stored = ft_strdup(pos + 1);
		*(pos + 1) = '\0';
		return (temp_saved);
	}
	temp_saved = ft_strdup(*stored);
	free(*stored);
	*stored = NULL;
	return (temp_saved);
}

char	*getnextline(int fd)
{
	char		*allocated;
	int			readen;
	static char	*stored;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	allocation(&stored, &allocated);
	if (!stored || !allocated)
		return (fireforce(&stored, &allocated), NULL);
	readen = 1;
	while (!(ft_strchr(stored, '\n')) && readen > 0)
	{
		readen = read(fd, allocated, BUFFER_SIZE);
		if (readen == 0)
			break ;
		if (readen == -1)
			return (fireforce(&stored, &allocated), NULL);
		allocated[readen] = '\0';
		stored = ft_strjoin(stored, allocated);
		if (!stored)
			return (fireforce(&stored, &allocated), NULL);
	}
	if (ft_strcmp(stored, "") == 0)
		return (fireforce(&stored, &allocated), NULL);
	return (free(allocated), returned_line(&stored, readen));
}
