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

typedef struct s_exit
{
	int	x;
	int	y;
	int	status;
}t_exit;

typedef struct s_list
{
	int	x;
	int	y;
	struct s_list	*next;
}t_list;

typedef struct s_size_map
{
	int	line;
	int	column;
}t_size_map;

typedef struct s_game
{
	t_list 		*item;
	t_exit		exit;
	t_player	player;
	t_size_map	size;
	char		**map;
}t_game;

/*------------- main.c -------------------------*/

char	**get_map(int fd, char **map);
char	**add_new_line(char **map, char *line, int *size);
void	free_tab(char **tab);
char	*ft_strcpy(char *dest, char *src);
void	print_map(char **map);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);














#endif
