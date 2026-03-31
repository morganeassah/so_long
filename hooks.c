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
		free_all(game);
	return (0);
	//if (keycode == KEY_R)
	//if (keycode == KEY_L)
	//if (keycode == KEY_U)
	//if (keycode == KEY_D)
}
