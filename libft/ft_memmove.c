/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 21:57:04 by jvictor-          #+#    #+#             */
/*   Updated: 2021/06/04 22:14:37 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*last_dest_cast;
	unsigned char	*last_src_cast;

	last_dest_cast = (unsigned char *)dest + n - 1;
	last_src_cast = (unsigned char *)src + n - 1;
	if (src < dest)
	{
		while (n--)
		{
			*last_dest_cast = *last_src_cast;
			last_dest_cast--;
			last_src_cast--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
