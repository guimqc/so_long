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
		is_map_valid(next_line);
		*map_adress = ft_strjoin_gnl(*map_adress, next_line);
		free(next_line);
	}
	close(fd);
}

// when map is fully read and logged look into the Map struct to see if it's a valid map
void	is_map_valid(char *line)
{
	(void) line;
}
