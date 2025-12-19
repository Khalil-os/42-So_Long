#include "../so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img_coin = NULL;
	game->img_exit = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_wall = NULL;
	game->map = NULL;
	game->map_height = 0;
	game->map_width = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->coins = 0;
	game->moves = 0;
}