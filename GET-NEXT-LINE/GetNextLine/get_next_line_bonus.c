
#include "get_next_line_bonus.h"



void	allocation(char **stored, char **allocated)
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

char	*returned_line(char **stored, int readen)
{
	char	*temp_stored;
	char	*pos;

	if (readen > 0)
	{
		temp_stored = *stored;
		pos = ft_strchr(temp_stored, '\n');
		*stored = ft_strdup(pos + 1);
		*(pos + 1) = '\0';
		return (temp_stored);
	}
	temp_stored = ft_strdup(*stored);
	free(*stored);
	*stored = NULL;
	return (temp_stored);
}

void	fireforce(char **stored, char **allocated)
{
	free(*stored);
	*stored = NULL;
	free(*allocated);
	allocated = NULL;
}

char	*get_next_line(int fd)
{
	static char	*stored[1024];
	char		*allocated;
	int			readen;

	if ((fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (NULL);
	allocation(&stored[fd], &allocated);
	if (!stored[fd] || !allocated)
		return (fireforce(&stored[fd], &allocated), NULL);
	readen = 1;
	while (!(ft_strchr(stored[fd], '\n')) && readen > 0)
	{
		readen = read(fd, allocated, BUFFER_SIZE);
		if (readen == 0)
			break ;
		if (readen == -1)
			return (fireforce(&stored[fd], &allocated), NULL);
		allocated[readen] = '\0';
		stored[fd] = ft_strjoin(stored[fd], allocated);
		if (!stored[fd])
			return (fireforce(&stored[fd], &allocated), NULL);
	}
	if (ft_strcmp(stored[fd], "") == 0)
		return (fireforce(&stored[fd], &allocated), NULL);
	return (free(allocated), returned_line(&stored[fd], readen));
}
