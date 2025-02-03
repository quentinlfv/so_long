#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>

# define SIZE 128
# define RIGTH 65363
# define LEFT 65361
# define UP 65362
# define DOWN 65364


typedef struct s_player
{
	int	x;
	int	y;
	int	status;
}t_player;

typedef struct s_size_map
{
	int	line;
	int	column;
}t_size_map;

typedef struct s_game
{
	t_player	player;
	t_size_map	size;
	char		**map;
	int			nbr_item;
	int			exit_status;
}t_game;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	char	**map_addr;
	t_game	*game_addr;
}t_data;

/*------------- main.c -------------------------*/

char **get_map(int fd, t_size_map *size_map);
char	**add_new_line(char **map, char *line, int *size);
void	free_tab(char **tab);
char	*ft_strcpy(char *dest, char *src);
void	print_map(char **map);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	init_struct(t_game *game);

/*--------------- check.c ---------------------*/

int	check_map(t_game *game);
int	check_pos(char pos, int	x, int y, t_game **game);
int	check_wall(char pos, int x, int y, t_size_map size);
int	check_exit(int	*exit_status);
int	check_player(int x, int y, t_player *player);
int	check_if_rectangle(int len_line, int nu_column);

/*------------- floodfill.c ---------------*/

void	helper_collect(char **map, int x, int y, char prev_val, int *status_exit);
void	helper_exit(char **map, int x, int y, char prev_val, int *coins);
int	floodFill(char **map, int x, int y, t_size_map *size_map, int  total_collectibles);
char	**copy_map(char **prev_map, t_size_map *size_map);
int		check_floodFill(char **map);

/*-------------- start_game.c --------------*/

void	start_game(t_game *game);
void	put_img_to_window(t_data *data, void *asset, int x, int y);
int	on_keypress(int	keysym, t_data *data);
int		on_destroy(t_data *data);
int	assign_assets_to_img(t_data *data);
void	put_map_to_window(t_data *data);
void	move_rigth(t_data *data, char **map, t_player *player);

/*------------- move.c -------------------*/


void	move_rigth(t_data *data, char **map, t_player *player);
void	move_left(t_data *data, char **map, t_player *player);
void	move_up(t_data *data, char **map, t_player *player);
void	move_down(t_data *data, char **map, t_player *player);

#endif
