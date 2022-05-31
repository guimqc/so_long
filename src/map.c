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

void	read_map(char *map_path, t_map *map)
{
	char	*next_line;
	int		fd;

	map->map = NULL;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		map_error();
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		// log_map_spec(next_line);
		map->map = ft_strjoin_gnl(map->map, next_line);
		free(next_line);
	}
	close(fd);
}

// when map is fully read and logged look into the Map struct to see if it's a valid map
void	validate_map(t_map *map)
{
	(void) map;
}
