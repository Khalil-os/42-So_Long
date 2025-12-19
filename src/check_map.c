#include "../so_long.h"

static int	is_rectangular(t_game *game)
{
	int	len;
	int	i;

	i = 1;
	len = ft_strlen(game->map[0]);
	while(game->map[i])
	{
		if (ft_strlen(game->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}	

static int	is_blocked_by_walls(t_game *game)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = ft_strlen(game->map[0]);
	while(i < len)
	{
		if (game->map[j][i] != '1')
			return (0);
		i++;
	}
	j++;
	while (game->map[j + 1])
	{
		if (game->map[j][0] != '1' || game->map[j][len - 1] != '1')
			return (0);
		j++;
	}
	i = 0;
	while(i < len)
	{
		if (game->map[j][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	is_valid_char(t_game *game)
{
	int	num_p;
	int	num_e;
	int	len;
	int	i;
	int	j;

	i = 1;
	num_p = 0;
	num_e = 0;
	len = ft_strlen(game->map[0]);
	while (game->map[i + 1])
	{
		j = 1;
		while (j < len - 1)
		{
			if (game->map[i][j] == '1' || game->map[i][j] == '0')
			{
				j++;
				continue;
			}
			else if (game->map[i][j] == 'P')
			{
				num_p++;
				game->player_x = i;
				game->player_y = j;
			}
			else if (game->map[i][j] == 'E')
				num_e++;
			else if (game->map[i][j] == 'C')
				game->coins++;
			else
				return (0);
			j++;
		}
		i++;
	}
	if (num_e != 1 || num_p != 1 || game->coins < 1)
		return (0);
	return (1);
}

void	check_map(t_game *game)
{
	if (!game->map || game->map_height <= 0 || game->map_width <= 0)
		error_exit(game, "Error: Invalid map\n", 0);
	if (!is_rectangular(game))
		error_exit(game, "Error: Invalid map\n", 0);
	if (!is_blocked_by_walls(game))
		error_exit(game, "Error: Invalid map\n", 0);
	if (!is_valid_char(game))
		error_exit(game, "Error: Invalid map\n", 0);
}