/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvictor- <jvictor-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 00:00:43 by jvictor-          #+#    #+#             */
/*   Updated: 2022/01/15 23:55:18 by jvictor-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * @brief Convert a initial portion of the string pointed to by (*nptr) 
 * to an integer.
 * 
 * @param nptr String to convert.
 * @return int The converted value.
 */
int		ft_atoi(const char *nptr);

/**
 * @brief Erases the data in the (n) bytes of the memory starting 
 * at the location pointed to by (*s).
 * 
 * @param s Array to erase.
 * @param n Size of bytes or characters to erase (put '\0').
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Allocates memory space by the number of elements (nmemb)
 * and size (size) in bytes erasing what was previously in that 
 * memory space.
 *  
 * @param nmemb Number of elements.
 * @param size Size in bytes. ex: (sizeof(int)).
 * @return void* The pointer to the allocated memory.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Check whether (c) is alphanumeric.
 * 
 * @param c Character that will be verified.
 * @return int (1) case positive or (0) case negative.
 */
int		ft_isalnum(int c);

/**
 * @brief Check whether (c) is alphabetic (Uppercase or Lowercase).
 * 
 * @param c Character that will be verified.
 * @return int (1) case positive or (0) case negative.
 */
int		ft_isalpha(int c);

/**
 * @brief Check whether (c) is part of Table Ascii.
 * 
 * @param c Character that will be verified.
 * @return int (1) case positive or (0) case negative.
 */
int		ft_isascii(int c);

/**
 * @brief Check whether (c) is digit.
 * 
 * @param c Character that will be verified.
 * @return int (1) case positive or (0) case negative.
 */
int		ft_isdigit(int c);

/**
 * @brief Check whether (c) is printable character including space.
 * 
 * @param c Character that will be verified.
 * @return int (1) case positive or (0) case negative.
 */
int		ft_isprint(int c);

/**
 * @brief Transform an integer (n) into a string of char.
 * 
 * @param n Integer to transform.
 * @return char* String created through the integer number.
 */
char	*ft_itoa(int n);

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

/**
 * @brief Copies no more than (n) bytes from memory area (*src) to memory
 * area (*dest) stopping when charactere (c) is found.
 * 
 * @param dest Array that will receive the copy.
 * @param src Array source.
 * @param c Character fetched.
 * @param n Number of bytes to be copied.
 * @return void* A pointer to the next character in (*dest) after (c), or NULL
 * if (c) was not found in the first (n) characters of (*src).
 */
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

/**
 * @brief Scan the array (*s) no more than (n) bytes of memory 
 * for a charactere (c).
 * 
 * @param s Array to be scanned.
 * @param c Character fetched.
 * @param n Number of bytes to be scanned.
 * @return void* A pointer to the matching byte or NULL if the character
 * does not occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compare (n) bytes of memory area from (*s1) and (*s2).
 * 
 * @param s1 Array to compare.
 * @param s2 Array to compare.
 * @param n Number of bytes to compare.
 * @return int An integer less than, equal to, or greater than zero. If 
 * (n) is 0 the return is NULL, if the both (*s1) and (*s2) in the 
 * domain of the (n) bytes are equal the return is 0, but if is found
 * any difference the return is the result of = (*s1) - (*s2).
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copies (n) bytes from (*src) to (*dest).
 * 
 * @param dest Array that will receive the copy.
 * @param src Array source.
 * @param n Number of bytes to be copied.
 * @return void* Pointer (*dest) or NULL if (*src) & (*dest)
 * are empty.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies (n) bytes from (*src) to (*dest); If the (*src) smaller
 * than (*dest) the copy is done in reverse.
 * 
 * @param dest Array that will receive the copy
 * @param src Array source
 * @param n Number of bytes to be copied
 * @return void* Pointer (*dest) or NULL if (*src) & (*dest)
 * are empty
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Fill the first (n) bytes of the memory are pointed to by (s)
 * with the constant byte (c).
 * 
 * @param s Array that receives the constant byte.
 * @param c Constante byte to put.
 * @param n Number of bytes to fill the byte.
 * @return void* A pointer to the memory area (*s).
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Outputs/Write the charactere (c) choosing the file descriptor (fd)
 * like native function write.
 * 
 * @param c Character to outputs/write.
 * @param fd File descriptor.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief  Outputs/Write the string (*s) choosing the file descriptor (fd)
 * like native function write, and followed by a newline.
 * 
 * @param s String to outputs/write.
 * @param fd File descriptor.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs/Write the integer (n) choosing the file descriptor (fd)
 * like native function write.
 * 
 * @param n Integer to outputs/write.
 * @param fd File descriptor.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief Outputs/Write the string (*s) choosing the file descriptor (fd)
 * like native function write.
 * 
 * @param s String to outputs/write.
 * @param fd File descriptor.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Split the words from a string (*s) by a delimiter 
 * character (c) and assigns each word in an array.
 * 
 * @param s String to be split.
 * @param c Delimiter character.
 * @return char** Array of strings obtained by splitting.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Scan the string (*s) for a charactere (c).
 * 
 * @param s String to be scanned.
 * @param c Character fetched.
 * @return char* A pointer to the matching byte or NULL
 * if the character does not occur in the given string.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Create a duplicate of the string (*s).
 * 
 * @param s String to duplicate .
 * @return char* Pointer to a new string or NULL (can be freed with "free()").
 */
char	*ft_strdup(const char *s);

/**
 * @brief Concatenates the strings (*s1) and (*s2) to a new String.
 * 
 * @param s1 First string to concatenate.
 * @param s2 Second string to concatenate.
 * @return char* The new string or NULL.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Concatenate string (*src) on (*dest) and 
 * returns the new size of (*dest).
 * 
 * @param dest String that will receive the (*src) concatenation.
 * @param src String source to concatenation.
 * @param size Size of (*dest).
 * @return size_t New size of the (*dest).
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size);

/**
 * @brief Copies the (*src) to the (*dst).
 * 
 * @param dst String to receive the copies.
 * @param src String source.
 * @param dst_size Size of (*dst).
 * @return size_t Size of (*src).
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);

/**
 * @brief Count the number of the characters in the (*str)
 * excepted the NULL byte.
 * 
 * @param str String to be counted.
 * @return size_t Number of characters of the (*str).
 */
size_t	ft_strlen(const char *str);

/**
 * @brief Applies the function (f( )) to each character of the
 * string (*s) to create a new string.
 * 
 * @param s String source.
 * @param f Function to applie in every array.
 * @return char* The string transformed or NULL.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Compares (n) bytes of the two strings (*s1) and (*s2).
 * 
 * @param s1 String to compare.
 * @param s2 String to compare.
 * @param n The number of first bytes to compares
 * @return int An integer less than, equal to, or greater than zero. If 
 * (n) is 0 the return is NULL, if the both (*s1) and (*s2) in the 
 * domain of the (n) bytes are equal the return is 0, but if is found
 * any difference the return is the result of = (*s1) - (*s2).
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates a first occurrence of substring (*little) 
 * in a string (*big), where not more than (len) charactere are searched.
 * 
 * @param big String source.
 * @param little Sub-String searched.
 * @param len Sub-String size.
 * @return char* The pointer to the first occurrence of the substring (*little). 
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Locate a character (c) in the string (*s) and returns
 * the pointer to the first occurrence.
 * 
 * @param s String source.
 * @param c Charactere searched.
 * @return char* The pointer to the first occurrence of the character
 * (c) or NULL.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Allocates (with malloc(3)) and returns a copy of
 * (*s1) with the characters specified in (*set) removed
 * from the beginning and the end of the string.
 * 
 * @param s1 String to be trimmed.
 * @param set String with characters to be removed.
 * @return char* The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string (*s)
 * The substring begins at index (start) and is of maximum size (len).
 * 
 * @param s String source.
 * @param start Initial index .
 * @param len The maximum length of the substring.
 * @return char* The substring or Null if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Convert uppercase letter to lowercase.
 * 
 * @param c Letter to be converted.
 * @return int Letter converted.
 */
int		ft_tolower(int c);

/**
 * @brief Convert lowercase letter to uppercase.
 * 
 * @param c Letter to be converted.
 * @return int Letter converted.
 */
int		ft_toupper(int c);

#endif