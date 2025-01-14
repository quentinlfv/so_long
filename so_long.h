#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>


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

/*------------- floodfill.c ---------------*/

void	helper(char **map, int x, int y, char prev_val);
int	floodFill(char **map, int x, int y, t_size_map *size_map);
char	**copy_map(char **prev_map, t_size_map *size_map);
int		check_floodFill(char **map);











#endif
