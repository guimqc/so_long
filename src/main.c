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

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	void	*mlx;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (!valid_map(fd))
	{
		ft_printf("Error\nThis map isn't valid");
		exit(1);
	}
}
