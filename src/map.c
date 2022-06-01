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

static void	validate_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i] != '\n')
		if (map->map[i] != '1')
			map_error();
	i = (int)ft_strlen(map->map);
	while (map->map[--i] != '\n')
		if (map->map[i] != '1')
			map_error();
	if (map->exit != 1)
		map_error();
	if (map->collectible < 1)
		map_error();
	if (map->start != 1)
		map_error();
}

static void	log_map_spec(t_map *map, char *next_line)
{
	int	i;

	i = -1;
	while (next_line[++i] != '\0')
	{
		if (i == 0 && next_line[i] != '1')
			map_error();
		if (next_line[i] == 'E')
			map->exit += 1;
		if (next_line[i] == 'P')
			map->start += 1;
		if (next_line[i] == 'C')
			map->collectible += 1;
	}
	if (next_line[i - 2] != '1')
		map_error();
}

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
		log_map_spec(map, next_line);
		map->map = ft_strjoin_gnl(map->map, next_line);
		free(next_line);
	}
	validate_map(map);
	close(fd);
}
