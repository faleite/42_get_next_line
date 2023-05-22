/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:00:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/22 21:58:26 by faaraujo         ###   ########.fr       */
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

char	*copy_line(int fd)
{
	char	*line;

	line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!line)
		return (NULL);
	read(fd, line, BUFFER_SIZE);
	/* COLOCAR CARACTER NULO NO FINAL DA STRING*/
	/* line[end] = '\0'; */
	return (line);
}

char	*stash(char *s)
{
	static char stash[100];

	strcat(stash, s);
	return (stash);
}

/*
char	*copy_line(int fd)
{
    char *line;

    line = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    if (!line)
        return (NULL);
    read(fd, line, BUFFER_SIZE);
    COLOCAR CARACTER NULO NO FINAL DA STRING
    line[end] = '\0';
    return(line);
}*/

char	*get_next_line(int fd)
{
	char	*line;

	line = copy_line(fd);
	return (line);
}

int	main(void)
{
	/* char	*line; */
	/* int		i; */
	int		fd;

	fd = open("test.txt", O_RDONLY);
	stash(get_next_line(fd));
	printf("%s\n", stash(get_next_line(fd)));
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
