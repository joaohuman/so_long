/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:48:31 by jvictor-          #+#    #+#             */
/*   Updated: 2021/06/23 18:37:03 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*duplicated;

	if (!s)
		return (NULL);
	size = ft_strlen((char *)s);
	duplicated = (char *)malloc(size + 1);
	if (!duplicated)
		return (NULL);
	ft_strlcpy(duplicated, s, size + 1);
	return (duplicated);
}
