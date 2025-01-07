#include "so_long.h"

int	check_map(t_game *game)
{
	int	i;
	int	j;
	t_list tmp;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!check_wall(game->map[i][j], j, i, game->size))
				return (0);
			if (game->map[i][j] == 'E')
				if (!check_exit(j, i, game->exit))
					return (0);
			if (game->map[i][j] == 'P')
				if (!check_player(j, i, game->exit))
					return (0);
			if (game->map[i][j] == 'C')
			{
				tmp = new_item(j, i);
				if (!tmp)
					return (0);
				add_item(&game->item, tmp);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_wall(char pos, int x, int y, t_size_map size)
{
	if ((y == 1 || y == size.column) && pos != '1')
		return (0);
	if ((x == 1 || x = size.line) && pos != '1')
		return (0);
	return (1);
}

int	check_exit(char pos, int x, int y, t_exit exit)
{
	if (exit.status != 0)
		return (0);
	exit.status = 1;
	exit.x = x;
	exit.y = y;
	return (1);
}

int	check_player(int x, int y, t_player player)
{
	if (player.status != 0)
		return (0);
	player.status = 1;
	player.x = x;
	player.y = y;
	return (1);
}

t_list	*new_item(int x, int y)
{
	t_list	*item;

	item = malloc(sizeof(t_list));
	if (!item)
		return (NULL);
	item.x = x;
	item.y = y;
	item.next = NULL;
	return (item);
}

void	add_item(t_list **list, t_list *item)
{
	if (!list)
		
	while ((*list)->next != NULL)
		*list = (*list)->next;
	(*list)->next = item;
}
