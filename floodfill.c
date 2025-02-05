/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quelefev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:50:16 by quelefev          #+#    #+#             */
/*   Updated: 2025/02/05 17:05:08 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

char	**copy_map(char **prev_map, t_size_map *size)
{
	char	**new_map;
	int		i;

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

void	helper_exit(char **map, int x, int y, int *status_exit)
{
	if (map[x][y] == '1' || map[x][y] == 'V')
		return ;
	if (map[x][y] == 'E')
		*status_exit = 1;
	map[x][y] = 'V';
	helper_exit(map, x, y + 1, status_exit);
	helper_exit(map, x + 1, y, status_exit);
	helper_exit(map, x, y - 1, status_exit);
	helper_exit(map, x - 1, y, status_exit);
}

void	helper_collect(char **map, int x, int y, int *coins)
{
	if (map[x][y] == '1' || map[x][y] == 'V' || map[x][y] == 'E')
		return ;
	if (map[x][y] == 'C')
		(*coins)++;
	map[x][y] = 'V';
	helper_collect(map, x, y + 1, coins);
	helper_collect(map, x + 1, y, coins);
	helper_collect(map, x, y - 1, coins);
	helper_collect(map, x - 1, y, coins);
}

int	floodfill(t_game *game, t_size_map *size)
{
	char	**tmp_map;
	int		status_exit;
	int		collectibles;

	status_exit = 0;
	collectibles = 0;
	tmp_map = copy_map(game->map, size);
	helper_collect(tmp_map, game->player.x, game->player.y, &collectibles);
	free_tab(tmp_map);
	tmp_map = copy_map(game->map, size);
	helper_exit(tmp_map, game->player.x, game->player.y, &status_exit);
	free_tab(tmp_map);
	if (game->nbr_item != collectibles || status_exit != 1)
		return (ft_putstr("Error Floodfill\n"), 0);
	return (1);
}
