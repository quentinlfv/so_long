/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlefevre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:39:08 by qlefevre          #+#    #+#             */
/*   Updated: 2022/11/29 21:17:02 by qlefevre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_new_line(char *mem_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!mem_line[i])
		return (NULL);
	while (mem_line[i] && mem_line[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (mem_line[i] && mem_line[i] != '\n')
	{
		str[i] = mem_line[i];
		i++;
	}
	if (mem_line[i] == '\n')
	{
		str[i] = mem_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	get_rest(char *mem_line, char *buf)
{
	size_t	i;

	i = 0;
	while (mem_line[i] && mem_line[i] != '\n')
	i++;
	if (i < ft_strlen(mem_line))
		ft_strlcpy(buf, mem_line + i + 1, ft_strlen(mem_line) - i + 1);
	free(mem_line);
}

char	*get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*mem_line;
	char			*line;
	ssize_t			ret;

	ret = 1;
	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, buf, 0) == -1)
		return (NULL);
	mem_line = NULL;
	mem_line = ft_strjoin(mem_line, buf);
	while (!ft_strchr(mem_line, '\n') && ret != 0)
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret < 0)
			return (NULL);
		mem_line = ft_strjoin(mem_line, buf);
		if (!mem_line)
			return (NULL);
	}
	line = get_new_line(mem_line);
	get_rest(mem_line, buf);
	return (line);
}
