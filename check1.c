/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quelefev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:46:27 by quelefev          #+#    #+#             */
/*   Updated: 2025/02/05 17:01:06 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "get_next_line.h"

int	check_format(char *map)
{
	char	*format;
	int		len_map_file;

	len_map_file = ft_strlen(map);
	if (len_map_file < 5)
		return (ft_putstr("Wrong map format!\n"), 0);
	format = map + (len_map_file - 4);
	if (ft_strcmp(format, ".ber"))
		return (ft_putstr("Wrong map format!\n"), 0);
	return (1);
}

int	check_pos(char pos, int x, int y, t_game **game)
{
	if (!check_wall(pos, x, y, (*game)->size))
		return (ft_putstr("Wrong map!\n"), 0);
	if (pos == 'E')
		if (!check_exit(&(*game)->exit_status))
			return (ft_putstr("Too much exit!\n"), 0);
	if (pos == 'P')
		if (!check_player(x, y, &(*game)->player))
			return (ft_putstr("Too many player!\n"), 0);
	if (pos == 'C')
		(*game)->nbr_item++;
	if (pos != '1' && pos != '0' && pos != 'E' && pos != 'C' && pos != 'P')
		return (ft_putstr("Wrong map!\n"), 0);
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
