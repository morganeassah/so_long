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
//		ft_printf("Line %d: %s\n", i, line);
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
//	ft_printf("Total lines read: %d\n", i);
	return (i);
}

int	read_map(t_game *game, char *file_name)
{
	int	fd;
	int	i;
	int	j;

	game->map = malloc (sizeof(char *) * MAX_LINE);
	if (!game->map)
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		free(game->map);
		return (0);
	}
	i = copy_map(game, fd);
	fflush(stdout);
	if (i <= 0 || !is_map_ok(game->map, i))
	{
		j = 0;
		while (j < i)
			free(game->map[j++]);
		free(game->map);
		close(fd);
		return (0);
	}
	close (fd);
	return (1);
}

int	check_map(t_game *game, char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
	{
		if (file_name[i] != '.')
			i++;
		else
			if (file_name[i + 1] != 'b')
				return (0);
			else if (file_name[i + 2] != 'e')
				return (0);
			else if (file_name[i + 3] != "r")
				return (0);
			else if (file_name[i + 4])
				return (0);
	}
	if (!read_map(game, file_name))
		return (0);
	return (1);
}

int	is_map_ok(char **map, int lines)
{
	if (!walls(map, lines))
		return (0);
	if (!characters(map, lines))
		return (0);
	if (!is_rectangular(map, lines))
		return (0);
	return (1);
}
