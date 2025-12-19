#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"

# define TILE_SIZE 64

typedef struct s_game
{
	void	*mlx;
	void	*win;

	char	**map;
	int		map_width;
	int		map_height;

	int		player_x;
	int		player_y;

	int		coins;
	int		moves;

	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_coin;

}	t_game;

void	init_game(t_game *game);
void	start_game(t_game *game);

void	read_map(t_game *game, char *file);
void	check_map(t_game *game);

void	flood_fill(t_game *game);

void	load_images(t_game *game);
void	draw_map(t_game *game);

int		key_hook(int keycode, t_game *game);
void	move_player(t_game *game, int new_x, int new_y);

void	error_exit(t_game *game, char *msg, int use_perror);
#endif
