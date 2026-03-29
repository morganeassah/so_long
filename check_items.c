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

int	characters(char **map, int lines)
{
	int		i;
	int		j;
	t_count	count;

	i = 0;
	j = 0;
	count.count_e = 0;
	count.count_p = 0;
	count.count_c = 0;
	while (i < lines)
	{
		characters_u(map[i], &count);
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n'
				&& map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	if (count.count_e != 1 || count.count_p != 1
		|| count.count_c < 1)
		return (0);
	return (1);
}
