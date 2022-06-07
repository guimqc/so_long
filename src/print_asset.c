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
}

void	print_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win,
		game->display.floor, 65 * x, 65 * y);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win,
		game->display.player, 65 * x, 65 * y);
}

void	print_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win,
		game->display.floor, 65 * x, 65 * y);
}
