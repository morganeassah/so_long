/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:06:33 by massah            #+#    #+#             */
/*   Updated: 2026/03/29 16:06:37 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(char **map, int x, int y)
{
	if ( x < 0 || y < 0 || !map)
		return ;
	if (map[y] == NULL)
		return ;
	if ((size_t)x >= ft_strlen(map[y]))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'f')
		return ;
	map[y][x] = 'f';
	ft_flood_fill(map, y + 1, x);
	ft_flood_fill(map, y - 1, x);
	ft_flood_fill(map, y, x + 1);
	ft_flood_fill(map, y, x - 1);
}
