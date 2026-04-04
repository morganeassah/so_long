/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:16:23 by massah            #+#    #+#             */
/*   Updated: 2026/03/20 16:16:32 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	copy_map(t_game *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (i >= MAX_LINE)
		{
			free(line);
			return (0);
		}
		game->map[i++] = line;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	game->map_h = i * TILE_SIZE;
	game->map_w = count_length(game->map, 0) * TILE_SIZE;
	if (game->map_h > MAX_H || game->map_w > MAX_W)
	{
		ft_printf("Wrong map dimensions");
		return (0);
	}
	return (i);
}

int	read_map(t_game *game, char *file_name)
{
	int	fd;
	int	i;

	game->map = ft_calloc(MAX_LINE, sizeof (char *));
	if (!game->map)
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Map doesn't exist\n");
		free_map(game->map);
		game->map = NULL;
		return (0);
	}
	i = copy_map(game, fd);
	if (i <= 0 || !is_map_ok(game, i))
	{
		free_map(game->map);
		game->map = NULL;
		close(fd);
		return (0);
	}
	close (fd);
	return (1);
}

int	check_map_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 4)
		return (0);
	return (file_name[len - 4] == '.'
		&& file_name[len -3] == 'b'
		&& file_name[len - 2] == 'e'
		&& file_name[len - 1] == 'r');
}

int	is_map_ok(t_game *game, int lines)
{
	if (!walls(game->map, lines))
		return (0);
	if (!characters(game, lines))
		return (0);
	if (!is_rectangular(game->map, lines))
		return (0);
	return (1);
}

int	check_map(t_game *game, char *file_name)
{
	char	**copy;

	if (!check_map_extension(file_name))
	{
		ft_printf("Wrong file extension \n");
		return (0);
	}
	if (!read_map(game, file_name))
	{
		return (0);
	}
	copy = NULL;
	copy = map_clone(game->map, copy);
	if (!copy)
		return (0);
	find_player_pos(game);
	ft_flood_fill(copy, game->y_p, game->x_p);
	if (!check_flood_fill(copy))
	{
		ft_printf("Map is not playable\n");
		free_map(copy);
		return (0);
	}
	free_map(copy);
	return (1);
}
