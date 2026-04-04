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
#  define MAX_W 1280
#  define MAX_H 720
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
	int		y_p;
	int		x_p;
	int		m_p;
	int		y_e;
	int		x_e;
	int		c;
	int		img_h;
	int		img_w;
	int		map_w;
	int		map_h;

	int		count_e;
	int		count_p;
	int		count_c;
	char	**map;
}	t_game;

// frees

void	free_map(char **map);
void	free_all(t_game *game);

//check map

char	**map_clone(char **map, char **copy);
void	characters_u(char *line, t_game *game);
void	ft_flood_fill(char **map, int x, int y);

int		is_rectangular(char **map, int lines);
int		same_line_length(char **map, int lines);
int		is_square(char **map, int height);
int		count_length(char **map, int i);
int		characters(t_game *game, int lines);
int		walls(char **map, int lines);
int		last_line(char **map, int lines);
int		first_line(char **map);
int		is_map_ok(t_game *game, int lines);
int		read_map(t_game *game, char *file_name);
int		check_map_extension(char *file_name);
int		check_map(t_game *game, char *file_name);
int		check_flood_fill(char **copy);

//afficher map dans fenetre

int		print_map(t_game *game);

// fonctions avec mlx

int		close_window(t_game *game);
int		init_mlx(t_game *game);
int		key_press(int keycode, t_game *game);
int		load_image(t_game *game);

// joueur

void	find_player_pos(t_game *game);
void	new_map(t_game *game, int keycode);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	is_d(t_game *game, int j, int i);
void	is_c(t_game *game, int j, int i);
void	is_e(t_game *game, int j, int i);
void	is_i(t_game *game, int j, int i);
void	is_0(t_game *game, int j, int i);

#endif
