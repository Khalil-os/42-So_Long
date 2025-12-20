#include "../so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	int	w;
	int	h;

	if (game->map[new_x][new_y] == '1')
		return;
	else if (game->map[new_x][new_y] == '0')
		game->map[game->player_x][game->player_y] = '0';
	else if (game->map[new_x][new_y] == 'C')
	{
		game->map[game->player_x][game->player_y] = '0';
		game->coins--;
		if (game->coins == 0)
		{
			mlx_destroy_image(game->mlx, game->img_exit);
			game->img_exit = mlx_xpm_file_to_image(game->mlx,
				"../textures/open-exit.xpm", &w, &h);
		}
	}
	else if (game->map[new_x][new_y] == 'E')
	{
		if (game->coins == 0)
		{
			ft_printf("You win !\n");
			free_game(game);
			exit(0);
		}
		return ;
	}
	game->map[new_x][new_y] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_printf("Move : %d", game->moves);
}
