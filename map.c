#include "so_long.h"
#include "get_next_line.h"

char **get_map(int fd, t_size_map *size_map)
{
	char	**map;
	char	*line;
	int		size;

	map = NULL;
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
	ft_strlcpy(new_map[i], line, ft_strlen(line));
	new_map[i + 1] = NULL;
	free(map);
	(*size)++;
	return (new_map);
}

int	check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!check_pos(game->map[i][j], i, j, &game))
				return (0);
			j++;
		}
		if (!check_if_rectangle(j, (game->size.column - 1)))
			return (0);
		i++;
	}
	if (game->nbr_item == 0)
		return (0);
	return (1);
}

int	check_if_rectangle(int len_line, int nu_column)
{
	if (len_line != nu_column)
		return (0);
	return (1);
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
