/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quelefev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:46:35 by quelefev          #+#    #+#             */
/*   Updated: 2025/02/14 15:02:51 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
		if (!check_if_rectangle(j, (game->size.column)))
			return (0);
		i++;
	}
	if (game->nbr_item == 0)
	{
		ft_putstr("Error\nNo collectible\n");
		return (0);
	}
	return (1);
}

int	check_if_rectangle(int len_line, int nu_column)
{
	if (len_line != nu_column)
	{
		ft_putstr("Error\nMap not rectangle\n");
		return (0);
	}
	return (1);
}
