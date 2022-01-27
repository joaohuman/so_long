/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 21:04:36 by jvictor-          #+#    #+#             */
/*   Updated: 2021/06/18 19:02:52 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cast;

	s_cast = (unsigned char *)s;
	while (n--)
	{
		if ((unsigned char)c == *s_cast)
			return ((void *)s_cast);
		s_cast++;
	}
	return (NULL);
}
