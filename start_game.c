#include "so_long.h"
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>


int	assign_assets_to_img(t_data *data)
{
	int		width;
	int		heigth;

	width = 128;
	heigth = 128;
	data->textures[0] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/Bricks.xpm", &width, &heigth);
	data->textures[1] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/Grass.xpm", &width, &heigth);
	data->textures[2] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/Character.xpm", &width, &heigth);
	data->textures[3] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/Stairs.xpm", &width, &heigth);
	data->textures[4] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/Coin.xpm", &width, &heigth);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall, 0, 0);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall, 128, 0);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, character, 256, 0);
	put_map_to_window(data);
	return (0);
}

void	put_map_to_window(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_addr[i])
	{
		j = 0;
		while (data->map_addr[i][j])
		{
			if (data->map_addr[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[0], (j * SIZE), (i * SIZE));
			if (data->map_addr[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[1], (j * SIZE), (i * SIZE));
			if (data->map_addr[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[2], (j * SIZE), (i * SIZE));
			if (data->map_addr[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[3], (j * SIZE), (i * SIZE));
			if (data->map_addr[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->textures[4], (j * SIZE), (i * SIZE));
			j++;
		}
		i++;
	}
}

int		on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_tab(data->map_addr);
	exit(0);
	return (0);
}

void	put_img_to_window(t_data *data, void *asset, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, asset, y, x);
}

void	update_player_pos()
{

}



int	on_keypress(int	keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	if (keysym == RIGTH)
	{
		move_rigth(data, data->game_addr->map, &data->game_addr->player);
		print_map(data->game_addr->map);
	}
	if (keysym == LEFT)
		move_left(data, data->game_addr->map, &data->game_addr->player);
	if (keysym == UP)
		move_up(data, data->game_addr->map, &data->game_addr->player);
	if (keysym == DOWN)
		move_down(data, data->game_addr->map, &data->game_addr->player);
	return (0);
}

void	start_game(t_game *game)
{
	t_data	data;

	data.map_addr = game->map;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return ;
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "SO_LONG");
	if (!data.win_ptr)
		return (free(data.mlx_ptr));
	data.game_addr = game;
	assign_assets_to_img(&data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
}
/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

