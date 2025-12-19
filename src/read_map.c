#include "../so_long.h"

static void	malloc_map(t_game *game, char *file)
{
	char	*line;
	int 	count;
	int		fd;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit(game, "Error");
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	game->map_height = count;
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		error_exit(game,"Error");
	close(fd);
}

void	read_map(t_game *game, char *file)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		i;

	malloc_map(game, file);
	fd = open(file,O_RDONLY);
	if (fd == -1)
		error_exit(game,"Error");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		tmp = line;
		line = ft_strtrim(tmp, "\n");
		free(tmp);
		game->map[i++] = line;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	if (game->map[0])
		game->map_width = ft_strlen(game->map[0]);
	close(fd);
	return ;
}
