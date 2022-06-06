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
# include "lib/mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct Map
{
	char	*map;
	int		width;
	int		height;
	int		exit;
	int		start;
	int		collectible;
}	t_map;

typedef struct Display
{
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*exit;
	void	*floor;
	void	*player;
	void	*collectible;
}	t_display;

typedef struct Game
{
	t_map		map;
	t_display	display;
}	t_game;

// map
void	read_map(char *map_path, t_map *map);

// display
void	display_map(t_display *display);

// error
void	arg_error(void);
void	map_error(void);

#endif
