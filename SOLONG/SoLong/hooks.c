
#include "so_long.h"

static void	events(int key, t_game *game, int *newpx, int *newpy)
{
	if (key == 65307)
	{
		thanossnap(game);
		exit(0);
	}
	else if (key == 119)
		(*newpy) -= 1;
	else if (key == 115)
		(*newpy) += 1;
	else if (key == 97)
		(*newpx) -= 1;
	else if (key == 100)
		(*newpx) += 1;
}

static void	newmap(t_game *game, int newpx, int newpy)
{
	if (game->map[newpy][newpx] == 'E' && game->collectible == 0)
	{
		game->moves++;
		ft_printf("move: %d\n", game->moves);
		thanossnap(game);
		exit(0);
	}
	if (game->map[newpy][newpx] == 'C')
		game->collectible--;
	if (game->onexite)
		game->map[game->py][game->px] = 'E';
	else
		game->map[game->py][game->px] = '0';
}

int	handlekeypress(int key, t_game *game)
{
	int	newpx;
	int	newpy;

	newpx = game->px;
	newpy = game->py;
	events(key, game, &newpx, &newpy);
	if (game->map[newpy][newpx] != '1')
	{
		newmap(game, newpx, newpy);
		game->onexite = (game->map[newpy][newpx] == 'E');
		game->map[newpy][newpx] = 'P';
		game->px = newpx;
		game->py = newpy;
		if (key == 119 || key == 115 || key == 100 || key == 97)
		{
			game->moves++;
			ft_printf("move: %d\n", game->moves);
		}
		rendermap(game);
	}
	return (0);
}

int	closegame(t_game *game)
{
	thanossnap(game);
	exit(0);
}
