#include "../so_long.h"

int main(int argc, char** argv)
{
	t_game	*game;
	int	len;

	game = malloc(sizeof(t_game));
	if (!game)
    	return (1);
	init_game(game);
	if (argc != 2)
		error_exit(game, "Error: Invalid arguments\n", 0);
	len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len - 4], ".ber", 4))
		error_exit(game, "Map file extention is wrong (It should be .ber).", 0);
	read_map(game, argv[1]);
	check_map(game);
	game->mlx = mlx_init();
	if (!game->mlx)
    	error_exit(game, "Error: mlx init failed\n", 0);
	game->win = mlx_new_window(
		game->mlx,
		game->map_width * TILE_SIZE,
		game->map_height * TILE_SIZE,
		"so_long"
	);
	if (!game->win)
    	error_exit(game, "Error: window init failed\n", 0);
	load_images(game);
	mlx_loop(game->mlx);
}
