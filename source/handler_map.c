/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:50:59 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/24 01:30:49 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_move(int key_code, t_map *map)
{
	if (key_code == 'w' || key_code == 0xff52)
		move_up(map);
	else if (key_code == 's' || key_code == 0xff54)
		move_down(map);
	else if (key_code == 'd' || key_code == 0xff53)
		move_right(map);
	else if (key_code == 'a' || key_code == 0xff51)
		move_left(map);
	print_images(map);
	return (0);
}

void	handler_map(t_map *map)
{
	mlx_expose_hook(map->win_ptr, print_images, map);
	print_images(map);
	mlx_hook(map->win_ptr, 2, 1L << 0, player_move, map);
	mlx_loop(map->mlx_ptr);
}

void	printi(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i] != NULL)
	{
		ft_putendl_fd(map->map[i], 1);
		i++;
	}
	ft_putendl_fd("\n", 1);
}
