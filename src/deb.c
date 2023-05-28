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
		/* if (*s2 == '\n') */
			/* break ; */
		i++;
	}	
	s3[i] = '\0';
	//free((char *)s1);
	return (s3);
}

char	*del_line(char *s)
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
	return (s);
}

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

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buff(fd, buffer);
	if (!buffer)
		return (NULL);
	line = new_line(buffer);
	buffer = del_line(buffer);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;
	/* int		i; */

	fd = open("test1.txt", O_RDONLY);
	line = get_next_line(fd);
	/* printf("%s\n", line); */
	/* printf("\nFile Descriptor: %d\n\n", fd); */
	/* i = 1; */
	/* while (i <= 5) */
	/* { */
		/* line = get_next_line(fd); */
		/* printf("line [%02d]: %s", i, line); */
		/* printf("%s", line); */
		/* free(line); */
		/* i++; */
	/* } */
	/* printf("\nReturn value of read: %zd", read(fd, line, BUFFER_SIZE)); */
	close(fd);
	free(line);
	return (0);
}