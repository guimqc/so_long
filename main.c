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

void	print_map_info(t_map map)
{
	ft_printf("%s\n", map.map);
	ft_printf("height: %i\n", map.height);
	ft_printf("width: %i\n", map.width);
	ft_printf("#collectible %i\n", map.collectible);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		arg_error();
	read_map(argv[1], &game.map);
	print_map_info(game.map);
	display_map(&game);

	free(game.map.map);
}
