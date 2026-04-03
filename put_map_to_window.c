/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_to_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:57:48 by massah            #+#    #+#             */
/*   Updated: 2026/03/20 13:57:52 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_map_utils(t_game *game, int x, int y, int i)
{
	int	j;

	if (!game)
		return (0);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			x = j * TILE_SIZE;
			y = i * TILE_SIZE;
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->img_wall, x, y);
			else if (game->map[i][j] == '0')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->img_floor, x, y);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->img_collectible, x, y);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->img_exit, x, y);
			else if (game->map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->img_player, x, y);
			j++;
		}
		i++;
	}
	return (1);
}

int	print_map(t_game *game)
{
	int	i;
	int	x;
	int	y;

	if (!game || !game->map)
		return (0);
	i = 0;
	x = 0;
	y = 0;
	if (!print_map_utils(game, x, y, i))
		return (0);
	return (1);
}
