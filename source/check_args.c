/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:29:03 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/07 00:50:33 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("ERROR\nInvalid number of argument\n", 1);
		exit (0);
	}
	if (ft_strlen(argv[1]) <= 4)
	{
		ft_putstr_fd("ERROR\nInvalid argument\n", 1);
		exit (0);
	}
	if (ft_strnstr(argv[1], ".ber", 4))
	{
		ft_putstr_fd("ERROR\nThe argument must be of type \".ber\"\n", 1);
		exit (0);
	}
}
