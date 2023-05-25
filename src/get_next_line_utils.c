/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:32:29 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/25 21:49:33 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/**
 * @brief function locates the first occurrence	of c (converted	to a char) in
 * the string pointed to by s
 * The terminating null character is considered part of the string; therefore if
 * c is `\0', the functions locate the terminating `\0'.
 * @param s Pointer of string.
 * @param c character to be found (converted to char).
 * @return return a pointer to the located character, or NULL if the character 
 * does not appear in the string.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
