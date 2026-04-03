/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forme_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 16:35:37 by massah            #+#    #+#             */
/*   Updated: 2026/04/03 16:35:51 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	same_line_length(char **map, int lines)
{
	int	length;
	int	i;

	length = count_length(map, 0);
	if (!map || lines <= 0)
		return (0);
	i = 1;
	while (i < lines)
	{
		if (!map[i] || count_length(map, i) != length)
		{
			ft_printf("Map is not rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	first_line(char **map)
{
	int	j;

	j = 0;
	while (map[0][j] && map[0][j] != '\n')
	{
		if (map[0][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	last_line(char **map, int lines)
{
	int	j;

	j = 0;
	while (map[lines - 1][j] && map[lines - 1][j] != '\n')
	{
		if (map[lines - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
