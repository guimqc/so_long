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

static int	can_move(t_game *game, int new_x, int new_y)
{
	if (game->map.map_array[new_x][new_y] == 'w')
		return (0);
	if (game->map.map_array[new_x][new_y] == 'c')
	{
		game->map.collectible--;
		if (game->map.collectible == 0)
			game->can_exit = 1;
	}
	if (game->map.map_array[new_x][new_y] == 'e')
	{
		if (game->can_exit == 0)
			return (0);
		if (game->can_exit == 1)
			exit(0);
	}
	ft_printf("%i\n", game->player.moove += 1);
	return (1);
}

void	move(t_game *game, int x_variation, int y_variation)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + x_variation;
	new_y = game->player.y + y_variation;
	if (!can_move(game, new_x, new_y))
		return ;
	print_player(game, new_x, new_y);
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
