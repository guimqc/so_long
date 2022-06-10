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

int	key_hook(int keycode, t_game *game)
{
	(void) *game;
	ft_printf("key_code: %i\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int	mouse_hook(int mousecode, t_game *game)
{
	(void) *game;
	ft_printf("mouse_code: %i\n", mousecode);
	return (0);
}
