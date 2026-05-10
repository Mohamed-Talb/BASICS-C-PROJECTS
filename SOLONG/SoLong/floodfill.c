
#include "so_long.h"

static void	fill(char **map, int row, int col, char player)
{
	if (map[row][col] == '1' || map[row][col] == 'F')
		return ;
	map[row][col] = 'F';
	fill(map, row - 1, col, player);
	fill(map, row + 1, col, player);
	fill(map, row, col - 1, player);
	fill(map, row, col + 1, player);
}

void	floodfill(t_game *game)
{
	char	**dupmap;
	int		i;
	int		j;

	i = 0;
	dupmap = ft_strdup2(game->map);
	if (!dupmap || !dupmap[0])
		displayerrors(game, "memory allocation faild\n", 1);
	fill(dupmap, game->py, game->px, game->map[game->py][game->px]);
	while (dupmap[i])
	{
		j = 0;
		while (dupmap[i][j])
		{
			if (dupmap[i][j] == 'C' || dupmap[i][j] == 'E')
			{
				ft_freedouble(&dupmap);
				displayerrors(game,
					"Error\nnot all collectibles can be reached\n", 1);
			}
			j++;
		}
		i++;
	}
	ft_freedouble(&dupmap);
}
