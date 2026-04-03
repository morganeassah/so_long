/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:33:36 by massah            #+#    #+#             */
/*   Updated: 2026/04/03 15:33:41 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_game *game)
{
	free_all(game);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_all(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
	mlx_destroy_image(game->mlx_ptr, game->img_collectible);
	mlx_destroy_image(game->mlx_ptr, game->img_player);
	mlx_destroy_image(game->mlx_ptr, game->img_floor);
	mlx_destroy_image(game->mlx_ptr, game->img_exit);
	if (game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	}
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit (0);
}
