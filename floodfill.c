#include "so_long.h"

char	**copy_map(char **prev_map, t_size_map *size)
{
	char	**new_map;
	int	i;

	i = 0;
	new_map = malloc(sizeof(char *) * (size->line + 1));
	if (!new_map)
		return (NULL);
	while (i < size->line)
	{
			new_map[i] = malloc(sizeof(char) * (size->column));
			if (!new_map[i])
				return (NULL);
			ft_strcpy(new_map[i], prev_map[i]);
			i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	helper(char **map, int x, int y, char prev_val)
{
	printf("x = %d | y = %d | %s | %c\n", x, y, map[1], map[1][2]);
	if (prev_val == map[x][y] || map[x][y] == '1')
		return ;
	map[x][y] = 'P';
	helper(map, x, y + 1, map[x][y]); 
	helper(map, x + 1, y, map[x][y]); 
	helper(map, x, y - 1, map[x][y]); 
	helper(map, x - 1, y, map[x][y]);
}

int	floodFill(char **map, int x, int y, t_size_map *size)
{
	char	**tmp_map;

	tmp_map = copy_map(map, size);
	helper(tmp_map, x, y, 'Z');
	if (!check_floodFill(tmp_map))
		return (print_map(tmp_map), free_tab(tmp_map), printf("Error floodFill\n"), 0);
	free_tab(tmp_map);
	return (1);
}

int		check_floodFill(char **map)
{
	int	i;
	int	j;

	i = 0;
	print_map(map);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		printf("\n");
		i++;
	}
	return (1);
}
