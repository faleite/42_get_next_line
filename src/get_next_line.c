/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:00:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/28 16:23:19 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	printf("%s\n", line);
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
