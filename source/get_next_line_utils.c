/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:18:52 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/06 01:38:54 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*sft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	unsigned char	*allocated;
	size_t			i;

	total_size = size * nmemb;
	allocated = (unsigned char *)malloc(total_size);
	i = 0;
	if (allocated == 0)
		return (NULL);
	while (i < size)
	{
		allocated[i] = '\0';
		i++;
	}
	return (allocated);
}

int	sft_strchr_gnl(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (HAVNT_BRK_LINE);
	while (s[i])
	{
		if (s[i] == c)
			return (HAV_BRK_LINE);
		i++;
	}
	if (s[i] == c)
		return (HAV_BRK_LINE);
	return (HAVNT_BRK_LINE);
}

int	sft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*sft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*concat;

	i = 0;
	j = 0;
	concat = (char *)sft_calloc(sizeof(char), sft_strlen(s1)
			+ sft_strlen(s2) + 1);
	if (!concat)
		return (NULL);
	while (s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		concat[i] = s2[j];
		i++;
		j++;
	}
	concat[i] = '\0';
	return (concat);
}

char	*sft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size_s;
	size_t	max_len;

	size_s = sft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (size_s < start)
	{
		sub = (char *)sft_calloc(sizeof(char), 1);
		if (!sub)
			return (NULL);
		return (sub);
	}
	max_len = size_s - start;
	if (len > max_len)
		len = max_len;
	sub = (char *)sft_calloc(sizeof(char), len + 1);
	if (!sub)
		return (NULL);
	sft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
