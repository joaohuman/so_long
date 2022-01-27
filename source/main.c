/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 02:08:25 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/27 01:35:31 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	check_args(argc, argv);
	init_struct(&map);
	open_map(&map, argv[1]);
	remove_barn(&map);
	check_map(&map);
	map.mlx_ptr = mlx_init();
	map.win_ptr = mlx_new_window(map.mlx_ptr,
			map.map_width * 30, map.map_height * 30, "SoLong");
	handler_map(&map);
	free_mallocs(&map);
}
