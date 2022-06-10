/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvial <marvin@42quebec.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:46:01 by gvial             #+#    #+#             */
/*   Updated: 2022/05/26 11:46:03 by gvial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->map.x = 0;
	game->map.y = 0;
	game->map.map = NULL;
	game->map.exit = 0;
	game->map.start = 0;
	game->map.width = -1;
	game->map.height = 0;
	game->map.collectible = 0;
	game->player.x = 0;
	game->player.y = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		arg_error();
	init_game(&game);
	read_map(argv[1], &game.map);
	display_map(&game);
	// // place hooks between display_map and mlx_loop to print image on top of existing one and print player on new spot
	// mlx_put_image_to_window(game.display.mlx, game.display.mlx_win, game.display.floor, 65 * 1, 65 * 3);
	// mlx_put_image_to_window(game.display.mlx, game.display.mlx_win, game.display.player, 65 * 3, 65 * 2);
	mlx_loop(game.display.mlx);
	free(game.map.map);
}
