#include "so_long.h"
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>


int	send_to_window(t_data *data)
{
	void	*wall;
	void	*grass;
	int		width;
	int		heigth;

	width = 16;
	heigth = 16;
	wall = mlx_xpm_file_to_image(data->mlx_ptr, "assets/Bricks.xpm", &width, &heigth);
	grass = mlx_xpm_file_to_image(data->mlx_ptr, "assets/Grass.xpm", &width, &heigth);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, wall, 138, 0);
	return (0);
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

int	on_keypress(int	keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\n", keysym);
	return (0);
}

void	start_game(char **map)
{
	t_data	data;

	data.map_addr = map;
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return ;
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, "SO_LONG");
	if (!data.win_ptr)
		return (free(data.mlx_ptr));
	send_to_window(&data);
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

