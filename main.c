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

/*void	load_image(t_game *game)
{

}*/

int	init_struct(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("mlx init failed\n");
		exit (1);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_w, game->map_h, "so_long");
	if (!game->win_ptr)
		return (0);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "src/wall.xpm", &game->img_w, &game->img_h);
	if (!game->img_wall)
		return (0);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "src/player.xpm", &game->img_w, &game->img_h);
	if (!game->img_player)
		return (0);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "src/exit.xpm", &game->img_w, &game->img_h);
	if (!game->img_exit)
		return (0);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx_ptr, "src/item.xpm", &game->img_w, &game->img_h);
	if (!game->img_collectible)
		return (0);
	game->img_floor = mlx_xpm_file_to_image(game->mlx_ptr, "src/floor.xpm", &game->img_w, &game->img_h);
	if (!game->img_floor)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (ac != 2)
	{
		ft_printf("missing map\n");
		return (1);
	}
	if (!check_map(&game, av[1]))
	{
		return (1);
	}
	if (!init_struct(&game))
	{
		free_all(&game);
		return (0);
	}
	if (!game.img_player)
	{
		ft_printf("failed loading image\n");
		free_all(&game);
	}
	mlx_loop_hook(game.mlx_ptr, render, &game);
	mlx_hook(game.win_ptr, 17, 1L << 17, close_window, &game);
	mlx_hook(game.win_ptr, 2, 1L << 0, key_press, &game);
	mlx_loop(game.mlx_ptr);
	free_all(&game);
	return (0);
}
