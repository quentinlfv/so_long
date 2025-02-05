/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quelefev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:50:49 by quelefev          #+#    #+#             */
/*   Updated: 2025/02/05 16:50:52 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	init_struct(t_game *game)
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
