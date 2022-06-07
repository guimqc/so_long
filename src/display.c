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

static	void	create_img(t_display *display)
{
	display->wall = mlx_xpm_file_to_image(display->mlx, "img/wall.xpm", &display->img_width, &display->img_height);
	display->floor = mlx_xpm_file_to_image(display->mlx, "img/floor.xpm", &display->img_width, &display->img_height);
	display->player = mlx_xpm_file_to_image(display->mlx, "img/player.xpm", &display->img_width, &display->img_height);
}

void	display_map(t_game *game)
{
	game->display.mlx = mlx_init();
	create_img(&game->display);
	game->display.mlx_win = mlx_new_window(game->display.mlx, 65 * game->map.width, 65 * game->map.height, "so_long");
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65 * 0, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65 * 1, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65 * 2, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65 * 3, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65 * 4, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65 * 5, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65 * 6, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65 * 7, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65 * 8, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65 * 9, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65 * 10, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65 * 11, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65 * 12, 0);
	mlx_loop(game->display.mlx);
}
