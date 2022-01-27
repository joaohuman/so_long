/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:56:42 by jvictor-          #+#    #+#             */
/*   Updated: 2021/06/18 20:08:35 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_cast;
	char	*src_cast;
	int		i;

	dest_cast = (char *)dest;
	src_cast = (char *)src;
	i = 0;
	if (!(dest_cast) && !(src_cast))
		return (NULL);
	while (n--)
	{
		dest_cast[i] = src_cast[i];
		i++;
	}
	return (dest);
}
