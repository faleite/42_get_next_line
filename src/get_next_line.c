/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:00:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/06/01 21:42:44 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
        static char	*buffer;
        char	*line;

        if (fd < 0 || BUFFER_SIZE <= 0)
                return (NULL);
        line = NULL;
        buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buffer)
                return (NULL);
        if (read(fd, buffer, BUFFER_SIZE) < 0)
        {
               free (line);
               return (NULL);
        }
        while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
        {
                line = ft_strjoin(line, buffer);
                if (clean_line(buffer) == 1)
                            break ;
        }
        free(buffer);
        return (line);
}

/* char	*get_next_line(int fd) */
/* { */
        /* static char	buffer[BUFFER_SIZE + 1]; */
        /* char	*line; */

        /* if (fd < 0 || BUFFER_SIZE <= 0) */
                /* return (NULL); */
        /* line = NULL; */
        /* while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0) */
        /* { */
                /* line = ft_strjoin(line, buffer); */
                /* if (clean_line(buffer) == 1) */
                            /* break ; */
                /* if (read(fd, buffer, BUFFER_SIZE) < 0) */
                /* { */
                        /* free (line); */
                        /* return (NULL); */
                /* } */
        /* } */
        /* return (line); */
/* } */

int	main(void)
{
        char	*line;
        int		fd;
        int		i;

        fd = open("test1.txt", O_RDONLY);
        printf("\nFile Descriptor: %d\n\n", fd);
        i = 1;
        while (i <= 5)
        {
                line = get_next_line(fd);
                printf("%s", line);
                free(line);
                i++;
        }
        printf("\nReturn value of read: %zd", read(fd, line, BUFFER_SIZE));
        close(fd);
        return (0);
}
