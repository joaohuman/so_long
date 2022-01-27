/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 20:51:25 by jvictor-          #+#    #+#             */
/*   Updated: 2021/06/29 20:21:35 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	s_len;
	char			*substr;

	if (!s)
		return (NULL);
	i = -1;
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		substr = (char *)ft_calloc(sizeof(char), 1);
		if (!substr)
			return (NULL);
		return (substr);
	}
	if (len > ft_strlen(s + start))
		substr = (char *)ft_calloc(sizeof(char), (ft_strlen(s + start)) + 1);
	else
		substr = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!substr)
		return (NULL);
	while (++i < len)
		substr[i] = s[i + start];
	return (substr);
}
