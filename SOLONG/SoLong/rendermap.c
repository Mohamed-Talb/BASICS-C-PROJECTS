
#include "so_long.h"

static void	setimg(int x, int y, t_game *game, void **img)
{
	if (!game || !game->xpms)
		return ;
	if (game->map[y][x] == '1')
		*img = game->xpms->wall;
	else if (game->map[y][x] == 'P')
	{
		if (game->collectible > 0 && game->onexite)
			*img = game->xpms->ponexit;
		else
			*img = game->xpms->player;
	}
	else if (game->map[y][x] == 'C')
		*img = game->xpms->collect;
	else if (game->map[y][x] == 'E')
	{
		if (game->collectible > 0)
			*img = game->xpms->cexit;
		else
			*img = game->xpms->oexit;
	}
	else
		*img = game->xpms->floor;
}

void	rendermap(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	img = NULL;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			setimg(x, y, game, &img);
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, x * 48, y
					* 48);
			x++;
		}
		y++;
	}
}
