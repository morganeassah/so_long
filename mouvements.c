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

void	move_right(t_game *game)
{
	if (game->map[game->y_p][game->x_p + 1] != '1')
	{
		if (game->map[game->y_p][game->x_p] == 'D')
			is_d(game, 0, 1);
		if (game->map[game->y_p][game->x_p + 1] == 'C')
			is_c(game, 0, 1);
		else if (game->map[game->y_p][game->x_p + 1] == 'E')
			is_e(game, 0, 1);
		else if (game->map[game->y_p][game->x_p + 1] == 'I')
			is_i(game, 0, 1);
		else if (game->map[game->y_p][game->x_p + 1] == '0')
			is_0(game, 0, 1);
		game->x_p += 1;
		game->m_p++;
		ft_printf("Moves: %d\n", game->m_p);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->y_p][game->x_p - 1] != '1')
	{
		if (game->map[game->y_p][game->x_p] == 'D')
			is_d(game, 0, -1);
		else if (game->map[game->y_p][game->x_p - 1] == 'C')
			is_c(game, 0, -1);
		else if (game->map[game->y_p][game->x_p - 1] == 'E')
			is_e(game, 0, -1);
		else if (game->map[game->y_p][game->x_p - 1] == 'I')
			is_i(game, 0, -1);
		else if (game->map[game->y_p][game->x_p - 1] == '0')
			is_0(game, 0, -1);
		game->x_p -= 1;
		game->m_p++;
		ft_printf("Moves: %d\n", game->m_p);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->y_p + 1][game->x_p] != '1')
	{
		if (game->map[game->y_p][game->x_p] == 'D')
			is_d(game, 1, 0);
		else if (game->map[game->y_p + 1][game->x_p] == 'C')
			is_c(game, 1, 0);
		else if (game->map[game->y_p + 1][game->x_p] == 'E')
			is_e(game, 1, 0);
		else if (game->map[game->y_p + 1][game->x_p] == 'I')
			is_i(game, 1, 0);
		else if (game->map[game->y_p + 1][game->x_p] == '0')
			is_0(game, 1, 0);
		game->y_p += 1;
		game->m_p++;
		ft_printf("Moves: %d\n", game->m_p);
	}
}

void	move_up(t_game *game)
{
	if (game->map[game->y_p - 1][game->x_p] != '1')
	{
		if (game->map[game->y_p][game->x_p] == 'D')
			is_d(game, -1, 0);
		else if (game->map[game->y_p - 1][game->x_p] == 'C')
			is_c(game, -1, 0);
		else if (game->map[game->y_p - 1][game->x_p] == 'E')
			is_e(game, -1, 0);
		else if (game->map[game->y_p - 1][game->x_p] == 'I')
			is_i(game, -1, 0);
		else if (game->map[game->y_p - 1][game->x_p] == '0')
			is_0(game, -1, 0);
		game->y_p -= 1;
		game->m_p++;
		ft_printf("Moves: %d\n", game->m_p);
	}
}

void	new_map(t_game *game, int keycode)
{
	if (keycode == KEY_R)
		move_right(game);
	else if (keycode == KEY_L)
		move_left(game);
	else if (keycode == KEY_D)
		move_down(game);
	else if (keycode == KEY_U)
		move_up(game);
	print_map(game);
}
