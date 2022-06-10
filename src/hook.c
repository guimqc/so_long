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

#include "../so_long.h"
// a big problem right know is that unlike the player
// the collectibles, walls, floors and exit positions (x, y) aren't registered.

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		exit(0);
	if (game->player.y != 1)
		if (keycode == 13)
			print_player(game, game->player.x, game->player.y - 1);
	if (game->player.y != game->map.height -2)
		if (keycode == 1)
			print_player(game, game->player.x, game->player.y + 1);
	if (game->player.x != 1)
		if (keycode == 0)
			print_player(game, game->player.x - 1, game->player.y);
	if (game->player.x != game->map.width - 2)
		if (keycode == 2)
			print_player(game, game->player.x + 1, game->player.y);
	return (0);
}
