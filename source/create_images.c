/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:05:59 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/26 23:42:47 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_wall(t_map *map, int i, int j)
{
	int		width;
	int		height;
	char	*path;

	path = "./img/wall.xpm";
	map->img_wall = mlx_xpm_file_to_image(map->mlx_ptr, path, &width, &height);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->img_wall, j * 30, i * 30);
	mlx_destroy_image(map->mlx_ptr, map->img_wall);
}

void	print_player(t_map *map, int i, int j)
{
	int		width;
	int		height;
	char	*path;

	if (map->last_movement == 1 && map->mov_up == 1)
		path = "./img/player_l_r.xpm";
	if (map->last_movement == 1 && map->mov_up == 0)
		path = "./img/player_r_l.xpm";
	if (map->last_movement == 2 && map->mov_down == 1)
		path = "./img/player_l_l.xpm";
	if (map->last_movement == 2 && map->mov_down == 0)
		path = "./img/player_l_r.xpm";
	if (map->last_movement == 3 && map->mov_right == 1)
		path = "./img/player_r_l.xpm";
	if (map->last_movement == 3 && map->mov_right == 0)
		path = "./img/player_r_r.xpm";
	if (map->last_movement == 4 && map->mov_left == 1)
		path = "./img/player_l_l.xpm";
	if (map->last_movement == 4 && map->mov_left == 0)
		path = "./img/player_l_r.xpm";
	map->img_wall = mlx_xpm_file_to_image(map->mlx_ptr, path, &width, &height);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->img_wall, j * 30, i * 30);
	mlx_destroy_image(map->mlx_ptr, map->img_wall);
}

void	print_exit(t_map *map, int i, int j)
{
	int		width;
	int		height;
	char	*path;

	path = "./img/exit.xpm";
	map->img_wall = mlx_xpm_file_to_image(map->mlx_ptr, path, &width, &height);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->img_wall, j * 30, i * 30);
	mlx_destroy_image(map->mlx_ptr, map->img_wall);
}

void	print_collectable(t_map *map, int i, int j)
{
	int		width;
	int		height;
	char	*path;

	path = "./img/collectable.xpm";
	map->img_wall = mlx_xpm_file_to_image(map->mlx_ptr, path, &width, &height);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->img_wall, j * 30, i * 30);
	mlx_destroy_image(map->mlx_ptr, map->img_wall);
}

void	print_space(t_map *map, int i, int j)
{
	int		width;
	int		height;
	char	*path;

	path = "./img/space.xpm";
	map->img_wall = mlx_xpm_file_to_image(map->mlx_ptr, path, &width, &height);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->img_wall, j * 30, i * 30);
	mlx_destroy_image(map->mlx_ptr, map->img_wall);
}
