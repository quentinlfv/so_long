#include "so_long.h"

int	on_keypress(int	keysym, t_data *data)
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

void	update_player_moves(int *count_moves)
{
	(*count_moves)++;
	printf("%d\n", *count_moves);
}

void	move_rigth(t_data *data, char **map, t_player *player)
{
	char *next_pos;

	next_pos = &map[player->x][player->y + 1];
	if (*next_pos == '1')
		return ;
	if (*next_pos == '0' | *next_pos == 'C')
	{
		put_img_to_window(data, data->textures[2], (player->x * SIZE), (player->y * SIZE) + SIZE);
		if (*next_pos == 'C')
			data->game_addr->nbr_item--;
		put_img_to_window(data, data->textures[1], player->x * SIZE, player->y * SIZE);
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
	char *next_pos;

	next_pos = &map[player->x][player->y - 1];
	if (*next_pos == '1')
		return ;
	if (*next_pos == '0' | *next_pos == 'C')
	{
		put_img_to_window(data, data->textures[2], (player->x * SIZE), (player->y * SIZE) - SIZE);
		if (*next_pos == 'C')
			data->game_addr->nbr_item--;
		put_img_to_window(data, data->textures[1], player->x * SIZE, player->y * SIZE);
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
	char *next_pos;

	next_pos = &map[player->x - 1][player->y];
	if (*next_pos == '1')
		return ;
	if (*next_pos == '0' | *next_pos == 'C')
	{
		put_img_to_window(data, data->textures[2], (player->x * SIZE) - SIZE, player->y * SIZE);
		if (*next_pos == 'C')
			data->game_addr->nbr_item--;
		put_img_to_window(data, data->textures[1], player->x * SIZE, player->y * SIZE);
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
	char *next_pos;

	next_pos = &map[player->x + 1][player->y];
	if (*next_pos == '1')
		return ;
	if (*next_pos == '0' | *next_pos == 'C')
	{
		put_img_to_window(data, data->textures[2], (player->x * SIZE) + SIZE, player->y * SIZE);
		if (*next_pos == 'C')
			data->game_addr->nbr_item--;
		put_img_to_window(data, data->textures[1], player->x * SIZE, player->y * SIZE);
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
