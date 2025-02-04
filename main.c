#include "so_long.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd;
	t_game game;

	if (ac != 2 || !check_format(av[1]))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (!fd)
		return (0);
	init_struct(&game);
	game.map = get_map(fd, &game.size);
	close(fd);
	if (!check_map(&game) || !floodFill(&game, &game.size))
		return (free_tab(game.map), 0);
	start_game(&game);
	free_tab(game.map);
	return (0);
}

void	print_map(char **map)
{
	int	i = 0;
	int	j;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
