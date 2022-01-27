/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:50:15 by jvictor-          #+#    #+#             */
/*   Updated: 2021/06/29 20:59:42 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length_word(char const *s, char c)
{
	size_t	counter;
	size_t	i;

	counter = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		i++;
		counter++;
	}
	return (counter);
}

static int	count_words(char const *s, char c)
{
	int	is_word;
	int	how_many;
	int	i;

	i = 0;
	is_word = 0;
	how_many = 0;
	while (s[i])
	{
		if (is_word == 0 && s[i] != c)
		{
			is_word = 1;
			how_many++;
		}
		else if (is_word && s[i] == c)
			is_word = 0;
		i++;
	}
	return (how_many);
}

static void	free_table(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char	**allocates(char const *s, char c, char **table, char **table2)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		if (s[i] != c)
		{
			*table = ft_substr(&s[i], 0, length_word(&s[i], c));
			if (!table)
			{
				free_table(table);
				return (NULL);
			}
			i += length_word(&s[i], c);
			table++;
		}
	}
	*table = NULL;
	return (table2);
}

char	**ft_split(char const *s, char c)
{
	char	**table;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	table = malloc((words + 1) * sizeof(char *));
	if (!table)
		return (NULL);
	table = allocates(s, c, table, table);
	if (!table)
		return (NULL);
	return (table);
}
