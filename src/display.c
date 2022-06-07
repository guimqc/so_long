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

// create images and save them into eg. display->wall

static	void	create_img(t_display *display)
{
	display->wall = mlx_xpm_file_to_image(display->mlx, "img/wall.xpm", &display->img_width, &display->img_height);
	display->floor = mlx_xpm_file_to_image(display->mlx, "img/floor.xpm", &display->img_width, &display->img_height);
	display->player = mlx_xpm_file_to_image(display->mlx, "img/player.xpm", &display->img_width, &display->img_height);
}

void	display_map(t_game *game)
{
	game->display.mlx = mlx_init();
	game->display.mlx_win = mlx_new_window(game->display.mlx, 700, 500, "so_long");
	create_img(&game->display);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 0, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 65, 0);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.wall, 0, 65);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.floor, 65, 65);
	mlx_put_image_to_window(game->display.mlx, game->display.mlx_win, game->display.player, 65, 65);
	mlx_loop(game->display.mlx);
}
