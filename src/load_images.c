#include "../so_long.h"

static void	draw_tile(t_game *game, int i, int j)
{
	int	x;
	int	y;

	x = j * TILE_SIZE;
	y = i * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_floor, x, y);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, x, y);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_player, x, y);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, x, y);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_coin, x, y);
}

static void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			draw_tile(game, i, j);
			j++;
		}
		i++;
	}
}

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
