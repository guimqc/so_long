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
	int		exit;
	int		start;
	int		collectible;
}	t_map;

typedef struct Game
{
	t_map map;
}	t_game;

// map
void	read_map(char *map_path, t_map *map);
void	validate_map(t_map *map);

// error
void	arg_error(void);
void	map_error(void);

#endif
