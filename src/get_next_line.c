/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:00:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/05/30 22:15:47 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Função que obtém um valor de uma entrada externa.
 * "Passos 1 e 2."
 */

char	*clean_line(char *buffer)
{
	char	*new;
	int	i;
	int	j;
	int	b;

	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	b = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!new)
		return (NULL);
	/* if (*buffer == '\n') */
		/* b = 1; */
	i++;
	while (buffer[i])
		new[j++] = buffer[i++];
	new[j] = '\0';
	free(buffer);
	buffer = new;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	/* static char	*buffer;	 */
	char	*line;
	int	val_rd;

	val_rd = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	/* buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)); */
	/* if (!buffer) */
		/* return(NULL); */
	while (*buffer || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		val_rd = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
		/* buffer = clean_line(buffer); */
		if (del_line(buffer) == 1)
			    break ;
		if (val_rd < 0)
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
