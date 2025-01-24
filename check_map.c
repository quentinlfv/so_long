#include "so_long.h"

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
			return (printf("j = %d | column = %d\n", j, game->size.column - 1), 0);
		i++;
	}
	return (1);
}

int	check_pos(char pos, int	x, int y, t_game **game)
{
	if (!check_wall(pos, x, y, (*game)->size))
		return (printf("Wrong map\n"), 0);
	if (pos == 'E')
		if (!check_exit(&(*game)->exit_status))
			return (0);
	if (pos == 'P')
		if (!check_player(x, y, &(*game)->player))
			return (0);
	if (pos == 'C')
		(*game)->nbr_item++;
	if (pos != '1' && pos != '0' && pos != 'E' && pos != 'C' && pos != 'P')
		return (0);
	return (1);
}

int	check_wall(char pos, int x, int y, t_size_map size)
{
	if ((y == 0 || y == size.column) && pos != '1')
		return (0);
	if ((x == 0 || x == size.line) && pos != '1')
		return (0);
	return (1);
}

int	check_exit(int *exit_status)
{
	if (*exit_status != 0)
		return (0);
	*exit_status = 1;
	return (1);
}

int	check_player(int x, int y, t_player *player)
{
	if (player->status != 0)
		return (0);
	player->status = 1;
	player->x = x;
	player->y = y;
	return (1);
}

int	check_if_rectangle(int len_line, int nu_column)
{
	if (len_line != nu_column)
		return (0);
	return (1);
}
