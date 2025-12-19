#include "../so_long.h"

static char	**copy_map(t_game *game)
{
    char **copy;
    int i;

    copy = malloc(sizeof(char *) * (game->map_height + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (game->map[i])
    {
        copy[i] = ft_strdup(game->map[i]);
        if (!copy[i])
            return (NULL);
        i++;
    }
    copy[i] = NULL;
    return (copy);
}

static void fill_all_place(char **map, int x, int y)
{
	if (x < 0 || y < 0 || !map[x] || !map[x][y])
		return ;
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	map[x][y] = 'V';
	fill_all_place(map, x + 1, y);
	fill_all_place(map, x - 1, y);
	fill_all_place(map, x, y + 1);
	fill_all_place(map, x, y - 1);
}

static int	check_flood_result(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	flood_fill(t_game *game)
{
	char	**map;

	map = copy_map(game);
	if (!map)
		error_exit(game, NULL, 1);
	fill_all_place(map, game->player_x, game->player_y);
	if (!check_flood_result(map))
	{
		free_map(map);
		error_exit(game, "Error: Invalid map\n", 0);
	}
	free_map(map);
}
