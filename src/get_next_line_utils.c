/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:32:29 by faaraujo          #+#    #+#             */
/*   Updated: 2023/06/01 21:10:20 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	if (s[len] == '\n')
		return (len + 1);
	return (len);
}

/** 
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
*/
char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(s3))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		s3[j++] = s2[i];
		if (s2[i++] == '\n')
			break ;
	}
	s3[j] = '\0';
	free(s1);
	return (s3);
}

int	del_line(char *s)
{
	int	i;
	int	j;
	int	b;

	i = 0;
	j = 0;
	b = 0;
	while (s[i])
	{
		if (b)
			s[j++] = s[i];
		if (s[i] == '\n')
			b = 1;
		s[i] = 0;
		i++;
	}
	return (b);
}

int    clean_line(char *buffer)
{
    int    i;
    int    j;
    int    result;
    int    end;
    
    i = 0;
    j = 0;
    result = 0;
    while (buffer[i] != '\n' && buffer[i])
    {
        buffer[i] = 0;
        i++;
    }
    buffer[i] = 0;
    i++;
    end = i;
    while (buffer[i])
        buffer[j++] = buffer[i++];
    //buffer[j] = '\0';
    while (end--)
        buffer[j++] = 0;
    return (result);
}

/* Nao esta sendo usada */
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

/* char	*new_line(char *buffer) */
/* { */
	/* char	*get_line; */
	/* char	*line; */
	/* size_t	len; */

	/* get_line = ft_strchr(buffer, '\n'); */
	/* if (get_line != NULL) */
	/* { */
		/* len = get_line - buffer; */
		/* line = strndup(buffer, len); */
	/* } */
/* } */

/* Nao esta sendo usada */
char	*new_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*int    clean_line(char *buffer)
{
    int    i;
    int    j;
    int    result;
    int    end;
    
    i = 0;
    j = 0;
    result = 0;
    while (buffer[i] && buffer[i] != '\n')
    {
        
        if (buffer[i] == '\n')
            result = 1;
        buffer[i] = 0;
        i++;
    }
    i++;
    end = i;
    while (buffer[i])
        buffer[j++] = buffer[i++];
    buffer[j] = '\0';
    while (end--)
        buffer[j++] = 0;
    return (result);
}*/
