/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 01:25:01 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/20 01:04:16 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (map->map_width > i)
	{
		if (map->map[0][i] != '1' || map->map[map->map_height - 1][i] != '1')
		{
			ft_putstr_fd("ERROR\nMap must be surrounded by walll\n", 1);
			free_exit(map);
		}
		i++;
	}
	i = 0;
	while (map->map_height > i)
	{
		if (map->map[i][0] != '1' || map->map[i][map->map_width - 1] != '1')
		{
			ft_putstr_fd("ERROR\nMap must be surrounded by wall\n", 1);
			free_exit(map);
		}
		i++;
	}
}

static void	count_pce(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'P')
			map->count_p += 1;
	if (map->map[i][j] == 'C')
			map->count_c += 1;
	if (map->map[i][j] == 'E')
			map->count_e += 1;
}

static void	verify_pce(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] != 'P' && map->map[i][j] != 'C'
				&& map->map[i][j] != 'E' && map->map[i][j] != '1'
				&& map->map[i][j] != '0')
			{
				ft_putstr_fd("ERROR\nInvalid characters in the map\n", 1);
				free_exit(map);
			}
			count_pce(map, i, j);
			j++;
		}
		i++;
	}
}

static void	validate_map(t_map *map)
{
	if (map->count_p != 1)
	{
		ft_putendl_fd("Error\nInvalid Map, allowed just one PLAYER", 1);
		free_exit(map);
	}
	if (map->count_e < 1)
	{
		ft_putendl_fd("Error\nInvalid Map, need at least one EXIT", 1);
		free_exit(map);
	}
	if (map->count_c < 1)
	{
		ft_putendl_fd("Error\nInvalid Map, need at least one COLLECTIBLE", 1);
		free_exit(map);
	}
}

void	check_map(t_map *map)
{
	check_walls(map);
	verify_pce(map);
	validate_map(map);
}
