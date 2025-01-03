#include "so_long.h"
#include "get_next_line.h"

int	main(int av, char **ac)
{
	int	fd;
	char	**map;

	map = NULL;
	fd = open(ac[1], O_RDONLY);
	if (!fd)
		return (0);
	get_map(fd, &map);
	close(fd);
	print_map(map);
}

void	get_map(int fd, char ***map)
{
	char	*line;
	char	**tmp;

	tmp = NULL;
	line = get_next_line(fd);
	*map = ft_calloc(ft_strlen(line) + 1, sizeof(char));
	if (!map)
		return ;
	printf("%s\n", line);
	ft_strcpy(*map[0], line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		tmp = copy_map_to_tmp(map, ft_strlen(line));
		*map = copy_tmp_to_map(tmp, line, ft_strlen(line));
		free(line);
	}
}	


char	**copy_map_to_tmp(char ***map, int len)
{
	char	**tmp;
	int	i;

	i = 0;
	len = ft_strlen(*map[i]);
	while (*map[i] != NULL)
		i++;
	tmp = malloc(sizeof(char *) * i + 1);
	if (!tmp)
		return (NULL);
	tmp[i] = NULL;
	i = 0;
	while (tmp[i] != NULL)
	{
		tmp[i] = malloc(sizeof(char) * len + 1);
		if (!tmp[i])
			return (NULL);
		ft_strcpy(*map[i], tmp[i]);
	}
	free_tab(*map);
	return (tmp);
}

char	**copy_tmp_to_map(char **tmp, char *line, int len)
{
	char	**map;
	int	i;

	i = 0;
	while (tmp[i] != NULL)
		i++;
	map = malloc(sizeof(char *) * i + 2);
	if (!map)
		return (NULL);
	map[i] = malloc(sizeof(char) * len + 1);
	if (!map[i])
		return (NULL);
	ft_strcpy(map[i], line);
	i++;
	while (map[i] != NULL)
	{
		map[i] = malloc(sizeof(char) * len + 1);
		if (!map[i])
			return (NULL);
		ft_strcpy(map[i], tmp[i -1]);
	}
	free_tab(tmp);
	return (map);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
}

void	print_map(char **map)
{
	int	i = 0;
	int	j;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		i++;
	}
}
