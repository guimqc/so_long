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

// create images and save them into eg. display->wall_img

void	display_map(t_display *display)
{
	display->mlx = mlx_init();
	display->mlx_win = mlx_new_window(display->mlx, 700, 500, "so_long");
	mlx_loop(display->mlx);
}
