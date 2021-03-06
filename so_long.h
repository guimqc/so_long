/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvial <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:49:50 by gvial             #+#    #+#             */
/*   Updated: 2022/05/25 16:49:55 by gvial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct Map
{
	char	*map;
	char	*map_path;
	char	map_array[1000][1000];
	int		x;
	int		y;
	int		width;
	int		height;
	int		exit;
	int		start;
	int		collectible;
}	t_map;

typedef struct Player
{
	int	x;
	int	y;
	int	moove;
}	t_player;

typedef struct Display
{
	void	*mlx;
	void	*mlx_win;
	int		img_width;
	int		img_height;
	void	*wall;
	void	*exit;
	void	*floor;
	void	*player;
	void	*collectible;
}	t_display;

typedef struct Game
{
	int			can_exit;
	t_map		map;
	t_player	player;
	t_display	display;
}	t_game;

// map
void	read_map(t_map *map);

// display
void	print_map(t_game *game);
void	display_map(t_game *game);
void	print_wall(t_game *game, int x, int y);
void	print_exit(t_game *game, int x, int y);
void	print_floor(t_game *game, int x, int y);
void	print_player(t_game *game, int x, int y);
void	print_collectible(t_game *game, int x, int y);

// hook
int		key_hook(int keycode, t_game *game);
int		close_x(t_game *game);

// error
void	arg_error(void);
void	map_error(t_map *map);
void	exit_n_free(t_map *map);

#endif
