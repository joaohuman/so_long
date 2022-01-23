/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 00:54:54 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/23 16:05:09 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_map(t_map *map, char *path_game)
{
	int	i;
	int	validator;

	i = 0;
	validator = 1;
	map->fd = open(path_game, O_RDONLY);
	if (map->fd == -1)
	{
		ft_putendl_fd("Error\nReading file", 1);
		exit (1);
	}
	while (validator)
	{
		map->map[i] = get_next_line(map->fd);
		if (map->map[i] == NULL)
			validator = 0;
		i++;
		map->map_height++;
	}
	close(map->fd);
	map->map_height -= 1;
	map->map_width = ft_strlen(&map->map[0][0]) - 1;
}
