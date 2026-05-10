
#include "so_long.h"

static int	countlines(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		displayerrors(game, "Error\nUnable to open map file\n", 1);
	line = ft_getnextline(fd);
	while (line != NULL)
	{
		free(line);
		line = ft_getnextline(fd);
		count++;
	}
	close(fd);
	return (count);
}

static void	storemap(t_game *game, int fd, int count)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_getnextline(fd);
	while (line != NULL)
	{
		if (i < count - 1)
			game->map[i] = ft_substr(line, 0, ft_strlen(line) - 1);
		else
			game->map[i] = ft_strdup(line);
		if (!game->map[i])
			displayerrors(game, "Error\nmemory allocation faild\n", 1);
		free(line);
		line = ft_getnextline(fd);
		i++;
	}
	game->map[i] = NULL;
}

void	readmap(t_game *game, char *file)
{
	int		count;
	int		fd;

	count = countlines(game, file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		displayerrors(game, "Error\nUnable to open map file\n", 1);
	game->map = malloc(sizeof(char *) * (count + 1));
	if (!game->map)
	{
		close(fd);
		displayerrors(game, "Error\nmemory allocation faild\n", 1);
	}
	storemap(game, fd, count);
	close(fd);
}
