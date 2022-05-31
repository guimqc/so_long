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

#include "../../so_long.h"

void	read_map(char *map_path, char **map_adress)
{
	char	*next_line;
	int		fd;

	*map_adress = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		map_error();
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		*map_adress = ft_strjoin_gnl(*map_adress, next_line);
		free(next_line);
	}
	close(fd);
}

// double loop that increment each time a \n is encountered
// inner loop checks for map requirements in each line
void	is_map_valid(char *map)
{
	(void) map;
}
