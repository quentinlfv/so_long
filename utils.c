/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quelefev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:46:10 by quelefev          #+#    #+#             */
/*   Updated: 2025/02/07 12:10:22 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_putchar(char c)
{
	int	nonsense;

	nonsense = write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	put_img_to_window(t_data *data, void *asset, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, asset, y, x);
}

void	img_to_win(t_data *data, int index_asset, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
					data->assets[index_asset], (x * SIZE), (y * SIZE));
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
