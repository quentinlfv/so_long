#include "so_long.h"
#include "get_next_line.h"

int	main(int av, char **ac)
{
	int	fd;
	t_game game;

	map = NULL;
	fd = open(ac[1], O_RDONLY);
	if (!fd)
		return (0);
	game.map = get_map(fd, &game.map);
	close(fd);
	print_map(map);
	free_tab(map);
	return (0);
}

char **get_map(int fd, char **map, t_size_map *size_map)
{
	char	*line;
	int	size;

	size = 0;
	line = get_next_line(fd);
	map = add_new_line(map, line, &size);
	size_map->column = ft_strlen(line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			map = add_new_line(map, line, &size);
	}
	size_map->line = size;
	return (map);
}

char	**add_new_line(char **map, char *line, int *size)
{
	char	**new_map;
	int	i;

	i = 0;
	new_map = malloc(sizeof(char *) * (*size + 2));
	if (!new_map)
		return (NULL);
	while (i < (*size))
	{
		new_map[i] = map[i];
		i++;
	}
	new_map[i] = malloc(sizeof(char) * (ft_strlen(line)));
	if (!new_map[i])
		return (NULL);
	ft_strlcpy(new_map[i], line, (ft_strlen(line) - 1));
	new_map[i + 1] = NULL;
	free(map);
	(*size)++;
	return (new_map);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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
