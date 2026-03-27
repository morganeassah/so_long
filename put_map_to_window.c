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

#include "so_long.h"

void print_map(t_game *game)
{
    int i;
    int j;
    int x;
    int y;

    if (!game || !game->map)
        return;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j] && game->map[i][j] != '\n')
        {
            x = j * TILE_SIZE;
            y = i * TILE_SIZE;

            if (game->map[i][j] == '1')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_wall, x, y);
            else if (game->map[i][j] == '0')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_floor, x, y);
    	    else if (game->map[i][j] == 'C')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_collectible, x, y);
            else if (game->map[i][j] == 'E')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_exit, x, y);
            else if (game->map[i][j] == 'P')
                mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, x, y);

            j++;
        }
        i++;
    }
}

/*void	print_map(t_game *game)
{
	ft_printf("print_map called\n");
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_player, 0, 0);
}*/
