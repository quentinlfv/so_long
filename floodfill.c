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

void	helper_exit(char **map, int x, int y, char prev_val, int *status_exit)
{
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	if (map[x][y] == 'E')
		*status_exit = 1;
	map[x][y] = 'V';
	helper_exit(map, x, y + 1, map[x][y], status_exit); 
	helper_exit(map, x + 1, y, map[x][y], status_exit); 
	helper_exit(map, x, y - 1, map[x][y], status_exit); 
	helper_exit(map, x - 1, y, map[x][y], status_exit);
}

void	helper_collect(char **map, int x, int y, char prev_val, int *coins)
{
	if (map[x][y] == '1' || map[x][y] == 'V' || map[x][y] == 'E')
		return ;
	if (map[x][y] == 'C')
		(*coins)++;
	map[x][y] = 'V';
	helper_collect(map, x, y + 1, map[x][y], coins); 
	helper_collect(map, x + 1, y, map[x][y], coins); 
	helper_collect(map, x, y - 1, map[x][y], coins); 
	helper_collect(map, x - 1, y, map[x][y], coins);
}

int	floodFill(char **map, int x, int y, t_size_map *size, int total_collectibles)
{
	char	**tmp_map_collect;
	char	**tmp_map_exit;
	int		status_exit = 0;
	int		coins = 0;

	tmp_map_collect = copy_map(map, size);
	tmp_map_exit = copy_map(map, size);
	helper_exit(tmp_map_exit, x, y, 'Z', &status_exit);
	helper_collect(tmp_map_collect, x, y, 'Z', &coins);
	if (total_collectibles != coins || status_exit != 1)
	{
		printf("coins == %d | status_exit == %d\n", coins, status_exit);
		return (free_tab(tmp_map_collect), free_tab(tmp_map_exit), printf("Error floodFill\n"), 0);
	}
	free_tab(tmp_map_collect);
	free_tab(tmp_map_exit);
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
