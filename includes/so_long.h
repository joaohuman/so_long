/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 01:39:12 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/24 00:36:39 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/resource.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include "libft.h"
# include "get_next_line.h"
# include <mlx.h>

typedef struct s_map {
	char	*map[100];
	char	*backup[100];
	int		map_height;
	int		map_width;
	int		fd;
	int		count_p;
	int		count_c;
	int		count_e;
	int		count_mov;
	void	*win_ptr;
	void	*mlx_ptr;
	int		player_col;
	int		player_line;
	char	*img_wall;
}	t_map;

int		main(int argc, char **argv);
void	check_args(int argc, char **argv);
void	open_map(t_map *map, char *path_game);
void	init_struct(t_map *map);
void	free_mallocs(t_map *map);
void	check_map(t_map *map);
void	remove_barn(t_map *map);
void	free_exit(t_map *map);
void	handler_map(t_map *map);
int		player_move(int key_code, t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_left(t_map *map);
void	move_right(t_map *map);
void	walk(t_map *map, char direction, int line, int col);
void	printi(t_map *map);
int		print_images(t_map *map);
void	print_wall(t_map *map, int i, int j);
void	print_player(t_map *map, int i, int j);
void	print_exit(t_map *map, int i, int j);
void	print_collectable(t_map *map, int i, int j);
void	print_space(t_map *map, int i, int j);

#endif
