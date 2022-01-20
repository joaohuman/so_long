/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 02:08:25 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/20 01:11:25 by jvictor-         ###   ########.fr       */
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
	free_mallocs(&map);
}
