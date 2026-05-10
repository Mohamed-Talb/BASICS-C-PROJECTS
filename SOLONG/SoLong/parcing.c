
#include "so_long.h"

static void	mapdimensions(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
		i++;
	game->hight = i;
	game->width = 0;
	if (game->hight > 0)
		game->width = ft_strlen(game->map[0]);
	if (game->width == 0 || game->hight == 0)
		displayerrors(game, "Error\ninvalide map\n", 1);
}

static void	checkwalls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->hight)
	{
		j = 0;
		while (j < game->width)
		{
			if (i == 0 || i == game->hight - 1 || j == 0 || j == game->width
				- 1)
				if (game->map[i][j] != '1')
					displayerrors(game, "Error\nMap is not enclosed by walls\n",
						1);
			j++;
		}
		i++;
	}
}

static void	checkelements(t_game *game)
{
	char	c;

	int (j), i = 0, exit = 0, start = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			c = game->map[i][j];
			if (c == 'P')
				(1) && (game->px = j, game->py = i, start += 1);
			else if (c == 'E')
				exit++;
			else if (c == 'C')
				game->collectible++;
			else if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				displayerrors(game, "Error\ninvalid element\n", 1);
			j++;
		}
		i++;
	}
	if (exit != 1 || start != 1 || game->collectible < 1)
		displayerrors(game, "Error\ninvalide elements\n", 1);
}

static void	mapisrectangle(t_game *game)
{
	int		i;
	size_t	firstrowlen;

	firstrowlen = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) != firstrowlen)
			displayerrors(game, "Error\nMap is not rectangular\n", 1);
		i++;
	}
}

void	parcing(t_game *game, char **av)
{
	char	*dot;

	dot = ft_strrchr(av[1], '.');
	if (!dot || dot == av[1] || *(dot - 1) == '/'
		|| ft_strcmp(dot, ".ber") != 0)
		displayerrors(game, "Error\nInvalid map extension Expected '.ber'\n",
			1);
	readmap(game, av[1]);
	if (!game->map || !game->map[0])
		displayerrors(game, "Error\nMap is empty or unreadable\n", 1);
	mapdimensions(game);
	mapisrectangle(game);
	checkelements(game);
	checkwalls(game);
	floodfill(game);
}
