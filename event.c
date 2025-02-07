/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quelefev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:50:01 by quelefev          #+#    #+#             */
/*   Updated: 2025/02/07 13:52:47 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	if (keysym == ESCAPE)
		on_destroy(data);
	if (keysym == RIGTH)
		move_rigth(data, data->game_addr->map, &data->game_addr->player);
	if (keysym == LEFT)
		move_left(data, data->game_addr->map, &data->game_addr->player);
	if (keysym == UP)
		move_up(data, data->game_addr->map, &data->game_addr->player);
	if (keysym == DOWN)
		move_down(data, data->game_addr->map, &data->game_addr->player);
	return (0);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_tab(data->map_addr);
	exit(0);
	return (0);
}
