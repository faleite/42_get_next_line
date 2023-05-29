/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:00:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/29 21:37:09 by faaraujo         ###   ########.fr       */
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
	/* while (ft_strchr(stash, '\n') == 0 && ret_read != 0) */
	/* { */
		ret_read = read(fd, stash, BUFFER_SIZE);
		if (ret_read == -1)
		{
			free(stash);
			stash = NULL;
			return (NULL);
		}
		stash[ret_read] = '\0';
		/* buffer = ft_strjoin(buffer, stash); */
	/* } */
	/* free(stash); */
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char	*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	/* buffer = read_buff(fd, buffer); */
	/* if (!buffer) */
		/* return (NULL); */
	 while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (del_line(buffer) == 1)
            		break ;
        	if (read(fd, buffer, 0) < 0)
        	{
            		free (line);
            		return (NULL);
        	}
	}
	return (line);
}

int	main(void)
{
	char	*line;
	/* char	*line1; */
	/* char	*line2; */
	int		fd;
	int		i;

	fd = open("test1.txt", O_RDONLY);
	/* line = get_next_line(fd); */
	/* line1 = get_next_line(fd); */
	/* line2 = get_next_line(fd); */
	/* printf("%s", line); */
	/* printf("%s", line1); */
	/* printf("%s", line2); */
	printf("\nFile Descriptor: %d\n\n", fd);
	i = 1;
	while (i <= 5)
	{
		line = get_next_line(fd);
		/* printf("line [%02d]: %s", i, line); */
		printf("%s", line);
		free(line);
		i++;
	}
	printf("\nReturn value of read: %zd", read(fd, line, BUFFER_SIZE));
	close(fd);
	/* free(line); */
	/* free(line1); */
	/* free(line2); */
	return (0);
}
