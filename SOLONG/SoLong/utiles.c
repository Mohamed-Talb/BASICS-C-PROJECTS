
#include "so_long.h"

void	initgame(t_game *game)
{
	game->py = -1;
	game->px = -1;
	game->width = 0;
	game->hight = 0;
	game->moves = 0;
	game->win = NULL;
	game->mlx = NULL;
	game->map = NULL;
	game->onexite = 0;
	game->collectible = 0;
	game->xpms = malloc(sizeof(t_textures));
	if (!game->xpms)
		displayerrors(game, "Error\nmemory allocation faild\n", 1);
	game->xpms->collect = NULL;
	game->xpms->oexit = NULL;
	game->xpms->cexit = NULL;
	game->xpms->floor = NULL;
	game->xpms->player = NULL;
	game->xpms->ponexit = NULL;
	game->xpms->wall = NULL;
}

void	displayerrors(t_game *game, char *error, int exitcode)
{
	thanossnap(game);
	ft_putstr_fd(error, 2);
	exit(exitcode);
}
