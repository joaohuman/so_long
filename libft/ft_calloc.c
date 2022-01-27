/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 21:45:47 by jvictor-          #+#    #+#             */
/*   Updated: 2021/06/17 22:04:19 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	unsigned char	*allocated;

	total_size = size * nmemb;
	allocated = (unsigned char *)malloc(total_size);
	if (allocated == 0)
		return (NULL);
	ft_bzero(allocated, total_size);
	return (allocated);
}
