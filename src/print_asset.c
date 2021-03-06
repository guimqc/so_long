/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvial <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:45:06 by gvial             #+#    #+#             */
/*   Updated: 2022/06/02 11:45:07 by gvial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_wall(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win,
		game->display.wall, 65 * x, 65 * y);
	game->map.map_array[x][y] = 'w';
}

void	print_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win,
		game->display.floor, 65 * x, 65 * y);
}

void	print_player(t_game *game, int x, int y)
{
	if (game->player.x != 0 && game->player.y != 0)
	{
		mlx_put_image_to_window(game->display.mlx, game->display.mlx_win,
			game->display.floor, 65 * game->player.x, 65 * game->player.y);
	}
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win,
		game->display.floor, 65 * x, 65 * y);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win,
		game->display.player, 65 * x, 65 * y);
	game->player.x = x;
	game->player.y = y;
}

void	print_exit(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win,
		game->display.floor, 65 * x, 65 * y);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win,
		game->display.exit, 65 * x, 65 * y);
	game->map.map_array[x][y] = 'e';
}

void	print_collectible(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win,
		game->display.floor, 65 * x, 65 * y);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win,
		game->display.collectible, 65 * x, 65 * y);
	game->map.map_array[x][y] = 'c';
}
