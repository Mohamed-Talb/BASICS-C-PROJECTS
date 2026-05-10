
#include "so_long.h"

static void	freetextures(t_game *game)
{
	if (!game || !game->xpms)
		return ;
	if (game->xpms->cexit)
		mlx_destroy_image(game->mlx, game->xpms->cexit);
	if (game->xpms->oexit)
		mlx_destroy_image(game->mlx, game->xpms->oexit);
	if (game->xpms->ponexit)
		mlx_destroy_image(game->mlx, game->xpms->ponexit);
	if (game->xpms->wall)
		mlx_destroy_image(game->mlx, game->xpms->wall);
	if (game->xpms->floor)
		mlx_destroy_image(game->mlx, game->xpms->floor);
	if (game->xpms->player)
		mlx_destroy_image(game->mlx, game->xpms->player);
	if (game->xpms->collect)
		mlx_destroy_image(game->mlx, game->xpms->collect);
	free(game->xpms);
	game->xpms = NULL;
}

static void	freegame(t_game *game)
{
	if (!game || !game->map)
	{
		return ;
	}
	ft_freedouble(&game->map);
}

static void	freewindow(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

void	thanossnap(t_game *game)
{
	freegame(game);
	freetextures(game);
	freewindow(game);
}
