/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quelefev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:05:08 by quelefev          #+#    #+#             */
/*   Updated: 2025/02/04 12:16:35 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_strcmp(const char *string1, const char *string2)
{
	unsigned int	i;

	i = 0;
	while ((string1[i] == string2[i]) && (string1[i] != 0))
		i++;
	return (((unsigned char)string1[i]) - ((unsigned char)string2[i]));
}
