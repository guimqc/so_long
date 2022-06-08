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

static void	init_map(t_map *map)
{
	map->x = 0;
	map->y = 0;
	map->map = NULL;
	map->exit = 0;
	map->start = 0;
	map->width = -1;
	map->height = 0;
	map->collectible = 0;
}

static void	validate_map(t_map *map)
{
	int	i;
	int	map_len;

	map_len = (int)ft_strlen(map->map);
	if (map->map[map_len - 1] == '\n')
		map_error();
	i = -1;
	while (map->map[++i] != '\n')
		if (map->map[i] != '1')
			map_error();
	i = map_len;
	while (map->map[--i] != '\n')
		if (map->map[i] != '1')
			map_error();
	if (map->exit != 1)
		map_error();
	if (map->collectible < 1)
		map_error();
	if (map->start != 1)
		map_error();
	if (map->height == map->width)
		map_error();
}

static void	log_map_spec(t_map *map, char *next_line)
{
	int	i;

	i = -1;
	while (next_line[++i] != '\n' && next_line[i] != '\0')
	{
		if (next_line[i] == 'E')
			map->exit += 1;
		if (next_line[i] == 'P')
			map->start += 1;
		if (next_line[i] == 'C')
			map->collectible += 1;
	}
	if (map->width == -1)
		map->width = i;
	if (i != map->width)
		map_error();
	if (next_line[0] != '1')
		map_error();
	if (next_line[i - 1] != '1')
		map_error();
}

static	void	validate_file_format(char *map_path)
{
	char	*format;
	char	*last_four_letter;

	format = ".ber";
	last_four_letter = &map_path[ft_strlen(map_path) - 4];
	if (ft_strncmp(format, last_four_letter, 4))
		map_error();
}

void	read_map(char *map_path, t_map *map)
{
	char	*next_line;
	int		fd;

	init_map(map);
	validate_file_format(map_path);
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
		map->height++;
	}
	validate_map(map);
	close(fd);
}
