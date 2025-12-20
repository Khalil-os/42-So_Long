#include "../so_long.h"

int		key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
        error_exit(game, "Exit\n", 0);
    else if (keycode == 119)
        move_player(game, game->player_x - 1, game->player_y);
    else if (keycode == 115)
        move_player(game, game->player_x + 1, game->player_y);
    else if (keycode == 97)
        move_player(game, game->player_x, game->player_y - 1);
    else if (keycode == 100)
        move_player(game, game->player_x, game->player_y + 1);
    draw_map(game);
    return (0);
}
