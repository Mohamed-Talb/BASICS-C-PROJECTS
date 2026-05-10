
#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_textures
{
	void		*oexit;
	void		*cexit;
	void		*wall;
	void		*floor;
	void		*player;
	void		*ponexit;
	void		*collect;
}				t_textures;

typedef struct s_game
{
	void		*win;
	void		*mlx;
	int			py;
	int			px;
	int			moves;
	int			width;
	int			onexite;
	int			hight;
	char		**map;
	int			collectible;
	t_textures	*xpms;
}				t_game;

void			floodfill(t_game *game);
int				handlekeypress(int key, t_game *game);
void			readmap(t_game *game, char *file);
void			initgame(t_game *game);
void			rendermap(t_game *game);
void			parcing(t_game *game, char **av);
void			thanossnap(t_game *game);
int				closegame(t_game *game);
void			displayerrors(t_game *game, char *error, int exitcode);

#endif