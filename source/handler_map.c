/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 15:50:59 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/23 16:47:47 by jvictor-         ###   ########.fr       */
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
}

void	handler_map(t_map *map)
{
	mlx_hook(map->mlx_ptr, 2, 1L << 0, player_move, map);
}
