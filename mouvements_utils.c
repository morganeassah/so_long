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

void	is_d(t_game *game, int j, int i)
{
	game->map[game->y_p + j][game->x_p + i] = 'P';
	game->map[game->y_p][game->x_p] = 'I';
}

void	is_c(t_game *game, int j, int i)
{
	game->count_c -= 1;
	if (game->count_c == 0)
		game->map[game->y_e][game->x_e] = 'E';
	game->map[game->y_p + j][game->x_p + i] = 'P';
	game->map[game->y_p][game->x_p] = '0';
}

void	is_e(t_game *game, int j, int i)
{
	if (game->count_c == 0)
	{
		game->map[game->y_p + j][game->x_p + i] = 'P';
		game->map[game->y_p][game->x_p] = '0';
		ft_printf("CONGRATS, YOU WIN!\n");
		free_all(game);
	}
	else
	{
		game->map[game->y_p + j][game->x_p + i] = 'D';
		game->map[game->y_p][game->x_p] = '0';
	}
}

void	is_i(t_game *game, int j, int i)
{
	game->map[game->y_p + j][game->x_p + i] = 'D';
	game->map[game->y_p][game->x_p] = '0';
}

void	is_0(t_game *game, int j, int i)
{
	game->map[game->y_p + j][game->x_p + i] = 'P';
	game->map[game->y_p][game->x_p] = '0';
}
