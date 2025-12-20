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

void	draw_map(t_game *game)
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