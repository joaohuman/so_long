/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 14:32:21 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/06 01:14:18 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/resource.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>

# define GNL_ERROR NULL
# define GNL_FOUND_LINEBREAK 1
# define GNL_FOUND_EOF 42
# define GNL_FOUND_EOF_NULL NULL
# define MAX_FILE_DESCRIPTOR RLIMIT_NOFILE
# define HAV_BRK_LINE 1
# define HAVNT_BRK_LINE 0
# define READ_AND_JOINED_OR_EOF 1
# define EVERYTHING_IS_OK 1

# define BUFFER_SIZE 1024

/**
 * @brief Allocates memory space by the number of elements (nmemb)
 * and size (size) in bytes erasing what was previously in that 
 * memory space.
 *  
 * @param nmemb Number of elements.
 * @param size Size in bytes. ex: (sizeof(int)).
 * @return void* The pointer to the allocated memory.
 */
void	*sft_calloc(size_t nmemb, size_t size);

/**
 * @brief Scan the string (*s) for a charactere (c)
 * *BREAK LINE
 * 
 * @param s String to be scanned.
 * @param c Character fetched.
 * @return int HAV_BRK_LINE (1) or HAVNT_BRK_LINE (0)
 */
int		sft_strchr_gnl(char *s, char c);

/**
 * @brief Concatenates the strings (*s1) and (*s2) to a new String.
 * 
 * @param s1 First string to concatenate.
 * @param s2 Second string to concatenate.
 * @return char* The new string or NULL.
 */
char	*sft_strjoin(char*s1, char *s2);

/**
 * @brief Count the number of the characters in the (*str)
 * excepted the NULL byte.
 * 
 * @param str String to be counted.
 * @return size_t Number of characters of the (*str).
 */
int		sft_strlen(char *str);

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string (*s)
 * The substring begins at index (start) and is of maximum size (len).
 * 
 * @param s String source.
 * @param start Initial index .
 * @param len The maximum length of the substring.
 * @return char* The substring or Null if the allocation fails.
 */
char	*sft_substr(char *s, unsigned int start, size_t len);

char	*get_next_line(int fd);

size_t	sft_strlcpy(char *dst, char *src, size_t size);

int		solver(int fd, char **buf_of_read, char **line, char **buf_of_line);

#endif