/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 01:39:12 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/20 01:10:09 by jvictor-         ###   ########.fr       */
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

typedef struct s_map {
	char	*map[100];
	char	*backup[100];
	int		map_height;
	int		map_width;
	int		fd;
	int		count_p;
	int		count_c;
	int		count_e;
	void	*win_ptr;
	void	*mlx_ptr;
}	t_map;

int		main(int argc, char **argv);
void	check_args(int argc, char **argv);
void	open_map(t_map *map, char *path_game);
void	init_struct(t_map *map);
void	free_mallocs(t_map *map);
void	check_map(t_map *map);
void	remove_barn(t_map *map);
void	free_exit(t_map *map);
#endif
