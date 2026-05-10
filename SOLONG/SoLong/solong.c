
#include "so_long.h"

static void	inittextures(t_game *game)
{
	int	w;
	int	h;

	game->xpms->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&w, &h);
	game->xpms->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&w, &h);
	game->xpms->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&w, &h);
	game->xpms->oexit = mlx_xpm_file_to_image(game->mlx, "textures/oexit.xpm",
			&w, &h);
	game->xpms->cexit = mlx_xpm_file_to_image(game->mlx, "textures/cexit.xpm",
			&w, &h);
	game->xpms->collect = mlx_xpm_file_to_image(game->mlx,
			"textures/collect.xpm", &w, &h);
	game->xpms->ponexit = mlx_xpm_file_to_image(game->mlx,
			"textures/ponexit.xpm", &w, &h);
	if (!game->xpms->wall || !game->xpms->floor || !game->xpms->player
		|| !game->xpms->oexit || !game->xpms->cexit || !game->xpms->collect
		|| !game->xpms->ponexit)
		displayerrors(game, "Error\nFailed to load one or more XPM files\n", 1);
}

static void	initwindow(t_game *game)
{
	int	w;
	int	h;

	w = game->width;
	h = game->hight;
	game->mlx = mlx_init();
	if (!game->mlx)
		displayerrors(game, "Error\nfaild to init conection\n", 1);
	game->win = mlx_new_window(game->mlx, w * 48, h * 48, "so_long");
	if (!game->win)
		displayerrors(game, "Error\nfaild to load new window\n", 1);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_putstr_fd("Error\nMemory allocation failed\n", 2);
		exit(1);
	}
	initgame(game);
	parcing(game, av);
	initwindow(game);
	inittextures(game);
	rendermap(game);
	mlx_hook(game->win, 2, (1L << 0), handlekeypress, game);
	mlx_hook(game->win, 17, (1L << 17), closegame, game);
	mlx_loop(game->mlx);
}
