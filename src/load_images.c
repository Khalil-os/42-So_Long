#include "../so_long.h"

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx,
		"../textures/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
		"../textures/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
		"../textures/player.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
		"../textures/exit.xpm", &w, &h);
	game->img_coin = mlx_xpm_file_to_image(game->mlx,
		"../textures/coin.xpm", &w, &h);
	if (!game->img_wall || !game->img_floor
		|| !game->img_player || !game->img_exit
		|| !game->img_coin)
		error_exit(game, "Error: Failed to load textures\n", 0);
	draw_map(game);
}
