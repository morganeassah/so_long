/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 15:02:14 by massah            #+#    #+#             */
/*   Updated: 2026/03/20 15:02:17 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	characters_u(char *line, t_count *count)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			count->count_e++;
		else if (line[i] == 'P')
			count->count_p++;
		else if (line[i] == 'C')
				count->count_c++;
		i++;
	}
}

int	is_square(char **map, int height)
{
	int	length;

	if (!map[0])
		return (0);
	length = count_length(map, 0);
	if (length == height)
	{
		ft_printf("map is square\n");
		return (0);
	}
	return (1);
}

int	count_length(char **map, int i)
{
	int	j;

	j = 0;
	if (!map[i])
		return (0);
	while (map[i][j] && map[i][j] != '\n')
	{
		j++;
	}
	return (j);
}

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
			ft_printf("map is not rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_rectangular(char **map, int lines)
{
	if (!is_square(map, lines))
		return (0);
	if (!same_line_length(map, lines))
		return (0);
	return (1);
}
