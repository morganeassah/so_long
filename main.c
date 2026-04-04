/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:28:01 by massah            #+#    #+#             */
/*   Updated: 2026/03/17 18:28:32 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_game *game)
{
	if (!print_map(game))
		return (0);
	return (1);
}

int	load_image(t_game *game)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "src/wall.xpm",
			&game->img_w, &game->img_h);
	if (!game->img_wall)
		return (0);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "src/player.xpm",
			&game->img_w, &game->img_h);
	if (!game->img_player)
		return (0);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "src/exit.xpm",
			&game->img_w, &game->img_h);
	if (!game->img_exit)
		return (0);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx_ptr, "src/item.xpm",
			&game->img_w, &game->img_h);
	if (!game->img_collectible)
		return (0);
	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr, "src/floor.xpm",
			&game->img_w, &game->img_h);
	if (!game->img_floor)
		return (0);
	return (1);
}

int	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("mlx init failed\n");
		exit (1);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_w,
			game->map_h, "so_long");
	if (!game->win_ptr)
		return (0);
	if (!load_image(game))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Missing map\n");
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	if (!check_map(&game, av[1]))
	{
		free_all(&game);
		return (0);
	}
	if (!init_mlx(&game))
	{
		free_all(&game);
		return (0);
	}
	mlx_loop_hook(game.mlx_ptr, render, &game);
	mlx_hook(game.win_ptr, 17, 1L << 17, close_window, &game);
	mlx_hook(game.win_ptr, 2, 1L << 0, key_press, &game);
	mlx_loop(game.mlx_ptr);
	free_all(&game);
	return (0);
}
