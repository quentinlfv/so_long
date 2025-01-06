#ifndef SO_LONG_H
# define SO_LONG_H
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
char	**get_map(int fd, char **map);
char	**copy_tab_to_tab(char **tab_src,char *line, int len);
char	**copy_map_to_tmp(char **map, int len);
char	**copy_tmp_to_map(char **tmp, char *line, int len);
void	free_tab(char **tab);
char	*ft_strcpy(char *dest, char *src);
void	print_map(char **map);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif
