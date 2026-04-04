/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:12:29 by massah            #+#    #+#             */
/*   Updated: 2026/03/20 13:12:34 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walls(char **map, int lines)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (!first_line(map))
		return (0);
	if (!last_line(map, lines))
		return (0);
	while (i < lines - 1)
	{
		if (map[i][0] != '1')
			return (0);
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (map[i][j - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	characters_u(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			game->count_e++;
		else if (line[i] == 'P')
			game->count_p++;
		else if (line[i] == 'C')
			game->count_c++;
		i++;
	}
}

int	characters(t_game *game, int lines)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < lines)
	{
		characters_u(game->map[i], game);
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != '\n' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	if (game->count_e != 1 || game->count_p != 1 || game->count_c < 1)
		return (0);
	return (1);
}
