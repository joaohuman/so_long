/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 22:35:49 by jvictor-          #+#    #+#             */
/*   Updated: 2021/06/23 21:11:50 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	char	*src_cast;

	i = 0;
	len = 0;
	src_cast = (char *)src;
	while (dest[len] && len < size)
		len++;
	i = len;
	while (src_cast[len - i] && (len + 1) < size)
	{
		dest[len] = src_cast[len - i];
		len++;
	}
	if (i < size)
		dest[len] = '\0';
	return (i + ft_strlen(src_cast));
}
