/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 23:05:59 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/24 01:15:15 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_wall(t_map *map, int i, int j)
{
	int		width;
	int		height;
	char	*path;

	path = "./img/barrel.xpm";
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

	path = "./img/player_l_l.xpm";
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

	path = "./img/grass.xpm";
	map->img_wall = mlx_xpm_file_to_image(map->mlx_ptr, path, &width, &height);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
		map->img_wall, j * 30, i * 30);
	mlx_destroy_image(map->mlx_ptr, map->img_wall);
}
