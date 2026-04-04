/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:14:10 by massah            #+#    #+#             */
/*   Updated: 2026/03/21 18:14:14 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		free_all(game);
		return (0);
	}
	if (keycode == KEY_R || keycode == KEY_L
		|| keycode == KEY_U || keycode == KEY_D)
	{
		new_map(game, keycode);
		return (0);
	}
	return (1);
}
