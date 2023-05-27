/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:00:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/27 18:40:58 by faaraujo         ###   ########.fr       */
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

/** 
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
*/
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	s3 = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!(s3))
		return (NULL);
	i = 0;
	while (len1--)
	{
		s3[i] = *s1++;
		i++;
	}
	while (len2--)
	{
		s3[i] = *s2++;
		i++;
	}	
	s3[i] = '\0';
	// free((char *)s1);
	return (s3);
}

/**
 * 1. Ler n_bytes (BUFFER_SIZE)
 * 
 * 2. Armazenar em uma variavel (stash) ate encontrar '\n'
 * 
 * 3. Ao encontrar a '\n' armazenar em uma variavel a linha
 * 
 * 4. limpar da (stash) a linha encontrada, deixando o que sobrou
 * 
 * 5. Retornar a linha encontrada
 * 
 * Obs: "Ao declarar a stash como static conseguimos manter a sobra
 * que foi linda alem da '\n'"
 */


/**
 * @brief Função que obtém um valor de uma entrada externa.
 * "Passos 1 e 2."
 */
char	*read_buff(int fd, char *buffer)
{
	char	*stash;
	int	ret_read;

	ret_read = 1;
	stash = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!stash)
		return (NULL);
	while (ft_strchr(stash, '\n') == 0 && ret_read != 0)
	{
		/**
		 * @brief read() -> return:
		 * 0 ser for lido ate o final
		 * -1 se a leitura falhar
		 * Outros valores (Ex.: 1), valores de bytes lidos
		 * */
		ret_read = read(fd, stash, BUFFER_SIZE);
		if (ret_read == -1)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		stash[ret_read] = '\0';
		buffer = ft_strjoin(buffer, stash);
	}
	free(stash);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*line;
	int	i;

	line = (char *)malloc(sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' || buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i])
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buff(fd, buffer);
	line = get_line(buffer);
	return (line); /* return (line); */
}

int	main(void)
{
	char	*line;
	/* int		i; */
	int		fd;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	/* printf("\nFile Descriptor: %d\n\n", fd); */
	/* i = 1; */
	/* while (i <= 5) */
	/* { */
		/* line = get_next_line(fd); */
		/* printf("line [%02d]: %s", i, line); */
		/* free(line); */
		/* i++; */
	/* } */
	/* printf("\nReturn value of read: %zd", read(fd, line, BUFFER_SIZE)); */
	close(fd);
	return (0);
}
