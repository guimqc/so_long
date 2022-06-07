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
	display->wall = mlx_xpm_file_to_image(display->mlx, "img/wall.xpm",
			&display->img_width, &display->img_height);
	display->floor = mlx_xpm_file_to_image(display->mlx, "img/floor.xpm",
			&display->img_width, &display->img_height);
	display->player = mlx_xpm_file_to_image(display->mlx, "img/player.xpm",
			&display->img_width, &display->img_height);
}

static	void	create_map(t_game *game)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = 0;
	while (game->map.map[i] != '\0')
	{
		if (game->map.map[i] == '1')
			print_wall(game, x, y);
		if (game->map.map[i] == '0')
			print_floor(game, x, y);
		if (game->map.map[i] == 'P')
			print_player(game, x, y);
		if (game->map.map[i] == '\n')
		{
			x = -1;
			y++;
		}
		x++;
		i++;
	}
}

void	display_map(t_game *game)
{
	game->display.mlx = mlx_init();
	create_img(&game->display);
	game->display.mlx_win = mlx_new_window(game->display.mlx,
			65 * game->map.width, 65 * game->map.height, "so_long");
	create_map(game);
	mlx_loop(game->display.mlx);
}
