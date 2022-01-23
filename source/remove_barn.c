/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_barn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:24:28 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/23 20:11:10 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_barn(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_height && map->map[i] != NULL)
	{
		j = 0;
		while (j <= map->map_width)
		{
			if (map->map[i][j] == '\n')
			{
				map->map[i][j] = '\0';
				break ;
			}
			j++;
		}
		map->backup[i] = ft_strdup(map->map[i]);
		i++;
	}
}
