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

void	move(t_game *game, int x_variation, int y_variation)
{
	int	player_y;
	int	player_x;

	player_x = game->player.x;
	player_y = game->player.y;
	if (game->can_exit == 0
		&& player_x + x_variation == game->exit_coordinate[0]
		&& player_y + y_variation == game->exit_coordinate[1])
		return ;
	print_player(game, player_x + x_variation, player_y + y_variation);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13)
		move(game, 0, -1);
	if (keycode == 1)
		move(game, 0, 1);
	if (keycode == 0)
		move(game, -1, 0);
	if (keycode == 2)
		move(game, 1, 0);
	return (0);
}
