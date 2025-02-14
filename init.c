/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quelefev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:50:49 by quelefev          #+#    #+#             */
/*   Updated: 2025/02/14 12:55:51 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	init_data_struct(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		data->assets[i] = NULL;
		i++;
	}
}

void	init_game_struct(t_game *game)
{
	game->player.x = 0;
	game->player.y = 0;
	game->player.status = 0;
	game->player.count_moves = 0;
	game->size.line = 0;
	game->size.column = 0;
	game->nbr_item = 0;
	game->exit_status = 0;
	game->map = NULL;
}
