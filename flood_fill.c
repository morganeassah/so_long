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

char	**map_clone(char **map, char **copy)
{
	int	len;
	int	i;

	len = 0;
	while (map[len])
		len++;
	copy = ft_calloc(len + 1, sizeof (char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
			return (NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	find_player_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->y_p = i;
				game->x_p = j;
			}
			if (game->map[i][j] == 'E')
			{
				game->y_e = i;
				game->x_e = j;
			}
			j++;
		}
		i++;
	}
}

int	check_flood_fill(char **copy)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'E' || copy[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_flood_fill(char **copy, int x, int y)
{
	if (x < 0 || y < 0 || !copy)
		return ;
	if (copy[y] == NULL)
		return ;
	if ((size_t)x >= ft_strlen(copy[y]))
		return ;
	if (copy[y][x] == '1' || copy[y][x] == 'f')
		return ;
	copy[y][x] = 'f';
	ft_flood_fill(copy, x, y + 1);
	ft_flood_fill(copy, x, y - 1);
	ft_flood_fill(copy, x + 1, y);
	ft_flood_fill(copy, x - 1, y);
}
