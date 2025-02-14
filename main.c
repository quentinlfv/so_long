/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quelefev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:50:57 by quelefev          #+#    #+#             */
/*   Updated: 2025/02/14 12:57:33 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	if (ac != 2 || !check_format(av[1]))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	init_game_struct(&game);
	game.map = get_map(fd, &game.size);
	if (!game.map)
		return (0);
	close(fd);
	if (!check_map(&game) || !floodfill(&game, &game.size))
		return (free_tab(game.map), 0);
	start_game(&game);
	free_tab(game.map);
	return (0);
}
