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
	map = get_map(fd, map);
	close(fd);
	print_map(map);
	free_tab(map);
	return (0);
}

char	**get_map(int fd, char **map)
{
	char	*line;
	char	**tmp;

	tmp = NULL;
	line = get_next_line(fd);
	map = malloc(sizeof(char *) * (1 + 1));
	if (!map)
		return (NULL);
	map[1] = NULL;
	map[0] = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!*map)
		return (NULL);
	ft_strcpy(map[0], line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
		{
			tmp = copy_tab_to_tab(map, NULL, ft_strlen(line));
			map = copy_tab_to_tab(tmp, line, ft_strlen(line));
		}
	}
	return (map);
}	

char	**copy_tab_to_tab(char **tab_src,char *line, int len)
{
	char	**tab_dest;
	int	i;

	i = 0;
	while (tab_src[i])
		i++;
	if (line != NULL)
		tab_dest = malloc(sizeof(char *) * (i + 2));
	else
		tab_dest = malloc(sizeof(char *) * (i + 1));
	if (!tab_dest)
		return (NULL);
	i = 0;
	while (tab_src[i] != NULL)
	{
		tab_dest[i] = malloc(sizeof(char) * (len + 1));
		if (!tab_dest[i])
			return (NULL);
		ft_strcpy(tab_dest[i], tab_src[i]);
		i++;
	}
	if (line != NULL)
	{
		tab_dest[i] = malloc(sizeof(char) * (len + 1));
		if (!tab_dest[i])
			return (NULL);
		ft_strcpy(tab_dest[i], line);
		i++;
	}
	tab_dest[i] = NULL;
	free_tab(tab_src);
	return (tab_dest);
}

char	**copy_map_to_tmp(char **map, int len)
{
	char	**tmp;
	int	i;

	i = 0;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
		i++;
	tmp = malloc(sizeof(char *) * (i + 1));
	if (!tmp)
		return (NULL);
	tmp[i] = NULL;
	i = 0;
	while (map[i] != NULL)
	{
		tmp[i] = malloc(sizeof(char) * (len + 1));
		if (!tmp[i])
			return (NULL);
		ft_strcpy(tmp[i], map[i]);
		i++;
	}
	free_tab(map);
	return (tmp);
}

char	**copy_tmp_to_map(char **tmp, char *line, int len)
{
	char	**map;
	int	i;

	i = 0;
	while (tmp[i] != NULL)
		i++;
	map = malloc(sizeof(char *) * (i + 2));
	if (!map)
		return (NULL);
	i = 0;
	while (tmp[i] != NULL)
	{
		map[i] = ft_calloc(len + 1, sizeof(char));
		if (!map[i])
			return (NULL);
		ft_strcpy(map[i], tmp[i]);
		i++;
	}
	map[i] = ft_calloc(len + 1, sizeof(char));
	if (!map[i])
		return (NULL);
	ft_strcpy(map[i], line);
	map[i + 1] = NULL;
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
	free(tab);
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
