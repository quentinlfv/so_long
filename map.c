/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quelefev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:51:28 by quelefev          #+#    #+#             */
/*   Updated: 2025/02/14 15:01:05 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "get_next_line.h"

char	**get_map(int fd, t_size_map *size_map)
{
	char	**map;
	char	*line;
	int		size;

	map = NULL;
	size = 0;
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr("Error\n");
		close(fd);
		return (NULL);
	}
	map = add_new_line(map, line, &size);
	size_map->column = ft_strlen(line) - 1;
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL)
			map = add_new_line(map, line, &size);
	}
	size_map->line = size;
	return (map);
}

char	**add_new_line(char **map, char *line, int *size)
{
	char	**new_map;
	int		len;
	int		i;

	i = 0;
	new_map = malloc(sizeof(char *) * (*size + 2));
	if (!new_map)
		return (NULL);
	while (i < (*size))
	{
		new_map[i] = map[i];
		i++;
	}
	if (line[ft_strlen(line)] == '\n')
		len = ft_strlen(line) - 1;
	else
		len = ft_strlen(line);
	new_map[i] = malloc(sizeof(char) * (ft_strlen(line)));
	if (!new_map[i])
		return (NULL);
	ft_strlcpy(new_map[i], line, len);
	new_map[i + 1] = NULL;
	free(map);
	(*size)++;
	return (new_map);
}
