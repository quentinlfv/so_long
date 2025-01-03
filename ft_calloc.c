/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quelefev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:49:12 by quelefev          #+#    #+#             */
/*   Updated: 2025/01/03 17:51:58 by quelefev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ar;

	ar = malloc(nmemb * size);
	if (!ar)
		return (NULL);
	ft_bzero(ar, nmemb * size);
	return (ar);
}
