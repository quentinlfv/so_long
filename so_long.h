#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define SIZE 128
# define ESCAPE 65307
# define RIGTH 65363
# define LEFT 65361
# define UP 65362
# define DOWN 65364


typedef struct s_player
{
	int	x;
	int	y;
	int	status;
	int	count_moves;
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

void	print_map(char **map);

/*------------------- init.c------------------*/
void	init_struct(t_game *game);

/*-------------- map.c ----------------------*/

int		check_map(t_game *game);
int		check_if_rectangle(int len_line, int nu_column);
char	**get_map(int fd, t_size_map *size_map);
char	**add_new_line(char **map, char *line, int *size);
void	free_tab(char **tab);

/*--------------- check.c ---------------------*/

int		check_format(char *map);
int		check_pos(char pos, int	x, int y, t_game **game);
int		check_wall(char pos, int x, int y, t_size_map size);
int		check_exit(int	*exit_status);
int		check_player(int x, int y, t_player *player);

/*------------- floodfill.c ---------------*/

void	helper_collect(char **map, int x, int y, int *status_exit);
void	helper_exit(char **map, int x, int y, int *coins);
int		floodFill(t_game *game, t_size_map *size);
char	**copy_map(char **prev_map, t_size_map *size_map);

/*-------------- start_game.c --------------*/
void	put_img_to_window(t_data *data, void *asset, int x, int y);
void	start_game(t_game *game);
int		on_destroy(t_data *data);
int		assign_assets_to_img(t_data *data);
void	put_map_to_window(t_data *data);

/*------------- move.c -------------------*/


int		on_keypress(int	keysym, t_data *data);
void	update_player_moves(int *count_moves);
void	move_rigth(t_data *data, char **map, t_player *player);
void	move_left(t_data *data, char **map, t_player *player);
void	move_up(t_data *data, char **map, t_player *player);
void	move_down(t_data *data, char **map, t_player *player);

/*--------------- others -------------------*/

int		ft_strcmp(const char *string1, const char *string2);
char	*ft_strcpy(char *dest, char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
