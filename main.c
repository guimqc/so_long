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
	game->can_exit = 0;
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
	game->player.moove = 0;
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		arg_error();
	init_game(&game);
	read_map(argv[1], &game.map);
	display_map(&game);
	mlx_key_hook(game.display.mlx_win, key_hook, &game);
	mlx_hook(game.display.mlx_win, 17, 0, close_x, &game);
	mlx_loop(game.display.mlx);
	free(game.map.map);
}
