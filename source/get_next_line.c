/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:18:39 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/06 01:39:07 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	sft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if ((src == 0) || (dst == 0))
		return (0);
	if (size > 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (sft_strlen(src));
}

int	read_and_join(int fd, char **buf_of_read,
						char **buf_of_line, int *bytes)
{
	char	*temporary_of_read;

	while (*bytes && sft_strchr_gnl(*buf_of_read, '\n') == HAVNT_BRK_LINE)
	{
		*bytes = read(fd, *buf_of_line, BUFFER_SIZE);
		(*buf_of_line)[*bytes] = '\0';
		if (*bytes < 0 || *bytes > BUFFER_SIZE)
		{
			free(*buf_of_line);
			return (-1);
		}
		temporary_of_read = *buf_of_read;
		*buf_of_read = sft_strjoin(temporary_of_read, *buf_of_line);
		free(temporary_of_read);
	}
	free(*buf_of_line);
	return (READ_AND_JOINED_OR_EOF);
}

char	*make_line_and_buf_of_read(char **line, char *buf_of_read, int bytes)
{
	int		position_of_brkline;
	int		len_of_buf_of_read;
	char	*new_buf_of_read;

	position_of_brkline = 0;
	len_of_buf_of_read = 0;
	new_buf_of_read = NULL;
	while (buf_of_read[position_of_brkline] != '\n'
		&& buf_of_read[position_of_brkline] != '\0')
		position_of_brkline++;
	*line = sft_substr(buf_of_read, 0, position_of_brkline + 1);
	if (bytes)
	{
		if (buf_of_read[position_of_brkline] == '\n')
			position_of_brkline++;
		len_of_buf_of_read = sft_strlen(buf_of_read + position_of_brkline);
		new_buf_of_read = sft_substr(buf_of_read, position_of_brkline,
				len_of_buf_of_read);
		if (!new_buf_of_read)
			return (NULL);
	}
	free(buf_of_read);
	return (new_buf_of_read);
}

int	solver(int fd, char **buf_of_read, char **line,
		char **buf_of_line)
{
	int	verification;
	int	bytes;

	bytes = 1;
	*buf_of_line = (char *)sft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buf_of_line)
		return (-1);
	verification = read_and_join(fd, buf_of_read, buf_of_line, &bytes);
	if (verification == -1)
		return (-1);
	*buf_of_read = make_line_and_buf_of_read(line, *buf_of_read, bytes);
	if (!bytes && *line[0] == '\0')
	{
		free(*line);
		return (GNL_FOUND_EOF);
	}
	return (EVERYTHING_IS_OK);
}

char	*get_next_line(int fd)
{
	static char		*buf_of_read;
	char			*line;
	char			*buf_of_line;
	int				verification;

	line = NULL;
	buf_of_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FILE_DESCRIPTOR
		|| read(fd, buf_of_line, 0) == -1)
		return (GNL_ERROR);
	if (!buf_of_read)
	{
		buf_of_read = (char *)sft_calloc(1, 1);
		if (!buf_of_read)
			return (GNL_ERROR);
	}
	verification = solver(fd, &buf_of_read, &line, &buf_of_line);
	if (verification == -1)
		return (GNL_ERROR);
	if (verification == GNL_FOUND_EOF)
		return (GNL_FOUND_EOF_NULL);
	return (line);
}
