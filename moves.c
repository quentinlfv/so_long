/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quelefev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:51:40 by quelefev          #+#    #+#             */
/*   Updated: 2025/02/05 17:17:11 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	update_player_moves(int *count_moves)
{
	(*count_moves)++;
	printf("%d\n", *count_moves);
}

void	move_rigth(t_data *data, char **map, t_player *player)
{
	char	*next_pos;

	next_pos = &map[player->x][player->y + 1];
	if (*next_pos == '1')
		return ;
	if (*next_pos == '0' | *next_pos == 'C')
	{
		put_img_to_window(data, data->textures[2], (player->x * SIZE), \
			(player->y * SIZE) + SIZE);
		if (*next_pos == 'C')
			data->game_addr->nbr_item--;
		put_img_to_window(data, data->textures[1], player->x * SIZE, \
			player->y * SIZE);
		map[player->x][player->y] = '0';
		*next_pos = 'P';
		player->y += 1;
		update_player_moves(&player->count_moves);
	}
	if (*next_pos == 'E')
	{
		if (data->game_addr->nbr_item == 0)
			on_destroy(data);
	}
}

void	move_left(t_data *data, char **map, t_player *player)
{
	char	*next_pos;

	next_pos = &map[player->x][player->y - 1];
	if (*next_pos == '1')
		return ;
	if (*next_pos == '0' | *next_pos == 'C')
	{
		put_img_to_window(data, data->textures[2], (player->x * SIZE), \
			(player->y * SIZE) - SIZE);
		if (*next_pos == 'C')
			data->game_addr->nbr_item--;
		put_img_to_window(data, data->textures[1], player->x * SIZE, \
			player->y * SIZE);
		map[player->x][player->y] = '0';
		*next_pos = 'P';
		player->y -= 1;
		update_player_moves(&player->count_moves);
	}
	if (*next_pos == 'E')
	{
		if (data->game_addr->nbr_item == 0)
			on_destroy(data);
	}
}

void	move_up(t_data *data, char **map, t_player *player)
{
	char	*next_pos;

	next_pos = &map[player->x - 1][player->y];
	if (*next_pos == '1')
		return ;
	if (*next_pos == '0' | *next_pos == 'C')
	{
		put_img_to_window(data, data->textures[2], (player->x * SIZE) - SIZE, \
			player->y * SIZE);
		if (*next_pos == 'C')
			data->game_addr->nbr_item--;
		put_img_to_window(data, data->textures[1], player->x * SIZE, \
			player->y * SIZE);
		map[player->x][player->y] = '0';
		*next_pos = 'P';
		player->x -= 1;
		update_player_moves(&player->count_moves);
	}
	if (*next_pos == 'E')
	{
		if (data->game_addr->nbr_item == 0)
			on_destroy(data);
	}
}

void	move_down(t_data *data, char **map, t_player *player)
{
	char	*next_pos;

	next_pos = &map[player->x + 1][player->y];
	if (*next_pos == '1')
		return ;
	if (*next_pos == '0' | *next_pos == 'C')
	{
		put_img_to_window(data, data->textures[2], (player->x * SIZE) + SIZE, \
			player->y * SIZE);
		if (*next_pos == 'C')
			data->game_addr->nbr_item--;
		put_img_to_window(data, data->textures[1], player->x * SIZE, \
			player->y * SIZE);
		map[player->x][player->y] = '0';
		*next_pos = 'P';
		player->x += 1;
		update_player_moves(&player->count_moves);
	}
	if (*next_pos == 'E')
	{
		if (data->game_addr->nbr_item == 0)
			on_destroy(data);
	}
}
