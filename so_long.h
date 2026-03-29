/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: massah <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:53:56 by massah            #+#    #+#             */
/*   Updated: 2026/03/20 16:53:59 by massah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

# ifndef TILE_SIZE
#  define TILE_SIZE 32
#  define MAX_LINE 1024
#  define KEY_ESC 65307
#  define KEY_R 65363
#  define KEY_L 65361
#  define KEY_D 65364
#  define KEY_U 65362
# endif

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	int	img_h;
	int	img_w;
	int	map_w;
	int	map_h;
	char	**map;
}	t_game;

typedef struct t_count
{
	int	count_e;
	int	count_p;
	int	count_c;
}	t_count;

//afficher map dans fenetre
void	print_map(t_game *game);
void	init_struct(t_game *game);
void	free_all(t_game *game);

//check map
int		is_rectangular(char **map, int lines);
int		same_line_length(char **map, int lines);
int		is_square(char **map, int height);
int		count_length(char **map, int i);
int		characters(char **map, int lines);
void	characters_u(char *line, t_count *count);
int		walls(char **map, int lines);
int		last_line(char **map, int lines);
int		first_line(char **map);
int		is_map_ok(char **map, int lines);
int		read_map(t_game *game, char *file_name);
int		check_map(t_game *game, char *file_name);

// fonctions avec mlx
int		close_window(t_game *game);
void	key_press(int keycode, t_game *game);

#endif
