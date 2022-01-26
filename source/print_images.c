/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 22:45:00 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/24 01:15:17 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	verify_char(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		print_wall(map, i, j);
	else if (map->map[i][j] == '0')
		print_space(map, i, j);
	else if (map->map[i][j] == 'P')
		print_player(map, i, j);
	else if (map->map[i][j] == 'E')
		print_exit(map, i, j);
	else if (map->map[i][j] == 'C')
		print_collectable(map, i, j);
}

int	print_images(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			verify_char(map, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
